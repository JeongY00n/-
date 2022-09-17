#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

struct Coord {
	int y, x, cost;
};

struct cmp {
	bool operator()(Coord a, Coord b) {
		if (a.cost > b.cost)return false;
		if (a.cost < b.cost)return true;
		return false;
	}
};

int n, k;
int map[10][10];
priority_queue<Coord, vector<Coord>, cmp> q;
int ans = 0;
int visited[10][10] = { 0, };

// 현재 좌표, 공사했는지 여부, 이동 거리
void dfs(Coord now, int check, int dist)
{
	int de = 1;
	

	int y = now.y;
	int x = now.x;
	int cost = now.cost;

	int fy[] = { 0,0,-1,1 };
	int fx[] = { -1,1,0,0 };

	for (int i = 0; i < 4; i++)
	{
		int ny = fy[i] + y;
		int nx = fx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (visited[ny][nx] == 1)continue;

		if (cost > map[ny][nx])
		{
			visited[ny][nx] = 1;
			dfs({ ny,nx,map[ny][nx] }, check, dist + 1);
			visited[ny][nx] = 0;
		}

		else if (cost > map[ny][nx] - k && check == 0)
		{
			
			visited[ny][nx] = 1;
			// dfs({ ny,nx,map[ny][nx] - k }, 1, dist + 1); 로 하면 안된다
			// 최대한 적게 깎아야 더 긴 길을 만들 수 있으므로
			// 이전 봉우리의 높이에서 -1만큼만 깎고 넘어가면 된다!!
			dfs({ ny,nx,map[y][x] - 1 }, 1, dist + 1);
			visited[ny][nx] = 0;
			
		}
	}

	if (ans < dist)
		ans = dist;

	return;
}



int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int maxi = 0;
		ans = 0;
		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (maxi <= map[i][j])
				{
					maxi = map[i][j];
					q.push({ i,j,map[i][j] });
				}
			}
		}

		while(!q.empty())
		{
			Coord now = q.top();
			q.pop();

			if (now.cost < maxi) continue;
			
			memset(visited, 0, sizeof(int) * (10 * 10));

			visited[now.y][now.x] = 1;

			dfs(now, 0, 1);

			visited[now.y][now.x] = 0;
		}
		

		cout << "#" << tc << " " << ans << "\n";
	}
	
	return 0;
}