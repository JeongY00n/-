#include <iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 최단 거리 
// union-find

struct Node {
	int row, col;
};
struct Edge {
	int from, to, cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		if (a.cost < b.cost)return false;
		if (a.cost > b.cost)return true;

		if (a.from < b.from)return false;
		if (a.from > b.from)return true;

		if (a.to < b.to)return false;
		if (a.to > b.to)return true;
		return false;
	}
};
int n, m;
int map[11][11];
int parents[10];


int Find(int now)
{
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);
}


void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	parents[pb] = pa;
}


void input() {
	for (int i = 1; i <= 6; i++)
	{
		parents[i] = i;
	}
	cin >> n >> m;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++)
			cin >> map[row][col];
	}
}


int cnt = 0;
int used[11][11] = { 0 };
vector<Node> LAND[7];

void land(Node start) {

	queue<Node> q;
	q.push(start);
	/*used[q.front().row][q.front().col] = 1;
	map[q.front().row][q.front().col] = cnt;*/

	int fr[] = { 0, 1,-1,0,0 };
	int fc[] = { 0, 0,0,-1,1 };

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();


		for (int i = 0; i < 5; i++) {
			int nr = now.row + fr[i];
			int nc = now.col + fc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
			if (map[nr][nc] == 0)continue;
			if (used[nr][nc] == 1)continue;
			used[nr][nc] = 1;
			map[nr][nc] = cnt;
			q.push({ nr,nc });
			LAND[cnt].push_back({ nr, nc });
		}
	}
}


priority_queue<Edge, vector<Edge>, cmp> pq;
int fr[] = { 1,-1,0,0 };
int fc[] = { 0,0,-1,1 };

void findLength(Node now, int length, int idx, int num) {

	int nr = now.row + fr[idx];
	int nc = now.col + fc[idx];

	if (map[nr][nc] == num)
		return;
	if (nr < 0 || nc < 0 || nr >= n || nc >= m)
		return;
	if (map[nr][nc] != 0 && map[nr][nc] != num)
	{
		if (length <= 1)return;
			//cout << length << " " << num << " " <<map[nr][nc]<< endl;
		pq.push({ num, map[nr][nc], length });
		return;
	}

	findLength({ nr,nc }, length + 1, idx, num);
}


void findBridge(Node now) {

	for (int i = 0; i < 4; i++) {
		int nr = now.row + fr[i];
		int nc = now.col + fc[i];

		if (nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
		if (map[nr][nc] != 0)continue;
		findLength({ now.row, now.col }, 0, i, map[now.row][now.col]);
	}
}

int main()
{
	input();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && used[i][j] == 0)
			{
				cnt++;
				land({ i,j });
			}
		}

	int check[7] = { 0 };

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < LAND[i].size(); j++) {
			int row = LAND[i][j].row;
			int col = LAND[i][j].col;

			findBridge(LAND[i][j]);
		}
	}

	int ans = 0, edge = 0;
	while (edge != cnt - 1)
	{
		
		if (pq.empty())break;
		
		int from = pq.top().from;
		int to = pq.top().to;
		int cost = pq.top().cost;

		pq.pop();

		if (Find(from) == Find(to))continue;
		
		Union(from, to);
		edge++;
		ans += cost;

	}

	if (edge != cnt - 1 || cnt==1)
		cout << -1;
	else
		cout << ans;


	return 0;
}

