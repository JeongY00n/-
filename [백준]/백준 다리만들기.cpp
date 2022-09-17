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

// 섬 위치를 확인하고 섬 번호로 값을 갱신
// 다리를 만들때 사용할 섬의 좌표 번호를 LAND[섬번호]에 넣어준다
void land(Node start) {

	queue<Node> q;
	q.push(start);

	// 섬의 크기가 하나인 것에 대해서도 적용하기 위해서 0,0도 추가
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


// 한 방향으로 나아가면서 앞에 다른 섬이 있는 경우 다리의 길이를 반환한다
// from, to, 다리 길이 정보를 담은 pq에 입력한다
// pq는 길이가 짧은 순서대로 정렬됨
priority_queue<Edge, vector<Edge>, cmp> pq;
int fr[] = { 1,-1,0,0 };
int fc[] = { 0,0,-1,1 };

void findLength(Node now, int length, int idx, int num) {

	int nr = now.row + fr[idx];
	int nc = now.col + fc[idx];

	// 앞으로 나아가는 중에 본인과 같은 번호가 존재하면 함수를 그냥 나옴
	if (map[nr][nc] == num)
		return;
	if (nr < 0 || nc < 0 || nr >= n || nc >= m)
		return;
	if (map[nr][nc] != 0 && map[nr][nc] != num)
	{
		if (length <= 1)return;
		pq.push({ num, map[nr][nc], length });
		return;
	}

	findLength({ nr,nc }, length + 1, idx, num);
}

// 점 위치에서 4가지 방향에 대해서 findLength를 해준다
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

	// 섬 찾기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && used[i][j] == 0)
			{
				cnt++;
				land({ i,j });
			}
		}

	// 섬들의 좌표값으로 다리 확인
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < LAND[i].size(); j++) {
			int row = LAND[i][j].row;
			int col = LAND[i][j].col;

			findBridge(LAND[i][j]);
		}
	}

	// 가장 짧은 다리 길이 먼저 더해주면서 만약 연결된 경우는 continue; 연결되지 않은 경우는 Untion해준다
	// edge개수 확인
	// 가장 짧은 총 다리 길이 계산
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

	// 섬의 갯수 - 1 보다 edge가 작은 경우 -1
	// 섬이 하나인 경우도 다리를 연결할 수 없기 때문에 -1
	if (edge != cnt - 1 || cnt == 1)
		cout << -1;
	else
		cout << ans;


	return 0;
}

