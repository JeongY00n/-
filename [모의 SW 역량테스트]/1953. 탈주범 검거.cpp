#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Coord {
	int y;
	int x;
	int num;
	int T;
};

int n, m, r, c, l;
int map[51][51];

int one[4][2] = { 1,0,-1,0,0,1,0,-1 };
// 2 ~ 7 => 0 ~ 5
int go[6][2][2] = {
	{ -1,0,1,0 },
	{ 0,-1,0,1 },
	{ -1,0,0,1 },
	{ 1,0,0,1 },
	{ 1,0,0,-1 },
	{ -1,0,0,-1 }
};

// 두 파이프가 연결되어있는지 확인
bool Find(Coord a, Coord b)
{
	int y = b.y;
	int x = b.x;
	int num = b.num;

	if (num == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = y + one[i][0];
			int nx = x + one[i][1];

			if (ny == a.y && nx == a.x)
				return true;
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int ny = y + go[num - 2][i][0];
			int nx = x + go[num - 2][i][1];

			if (ny == a.y && nx == a.x)
				return true;
		}
	}
	return false;
}


int bfs(Coord manhole)
{
	queue<Coord>q;
	q.push(manhole);

	int visited[51][51] = { 0 };

	//맨홀
	visited[r][c] = 1;

	int ans = 1;
	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();
		int de = 1;
		int y = now.y;
		int x = now.x;
		int num = now.num;
		int time = now.T;

		if (time == l)continue;

		if (num == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = y + one[i][0];
				int nx = x + one[i][1];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
				if (map[ny][nx] == 0)continue;
				if (visited[ny][nx] == 1)continue;
				if (time == l)continue;

				// 갈 수 있는 파이프인지 확인(2->3파이프로는 연결이 안되어서 갈 수 없음)
				if (!Find(now, { ny,nx,map[ny][nx] })) continue;
				visited[ny][nx] = 1;
				q.push({ ny,nx,map[ny][nx], time + 1 });
				ans++;
			}
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = y + go[num - 2][i][0];
				int nx = x + go[num - 2][i][1];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
				if (map[ny][nx] == 0)continue;
				if (visited[ny][nx] == 1)continue;
				if (time == l)continue;

				//갈 수 있는 파이프인지 확인(2->3파이프로는 연결이 안되어서 갈 수 없음)
				if (!Find(now, { ny,nx,map[ny][nx] })) continue;
				visited[ny][nx] = 1;
				q.push({ ny,nx,map[ny][nx], time + 1 });
				ans++;
			}
		}
		
	}

	return ans;

}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> r >> c >> l;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> map[i][j];

		int ans = bfs({ r,c,map[r][c], 1 });

		cout << "#" << tc << " " << ans << "\n";

	}




	return 0;
}