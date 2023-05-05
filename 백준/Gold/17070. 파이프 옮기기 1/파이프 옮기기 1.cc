#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct Node {
	int y1;
	int x1;
	int y2;
	int x2;
};

int n;
int map[17][17] = { 0 };
int cnt = 0;

void go() {

	queue<Node> q;
	q.push({ 1, 1, 1, 2 });
	int used[17][17] = { 0 };
	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		//cout << now.y2 << "," << now.x2 << endl;

		if (now.y2 == n && now.x2 == n)
		{
			cnt++;
		}

		int horizontal_y[] = { 0, 1 };
		int horizontal_x[] = { 1, 1 };

		int vertical_y[] = { 1, 1 };
		int vertical_x[] = { 0, 1 };

		int incline_y[] = { 0, 1, 1 };
		int incline_x[] = { 1, 0, 1 };

		//가로
		if (now.y2 - now.y1 == 0) {
			
			for (int i = 0; i < 2; i++) {
				int ny = now.y2 + horizontal_y[i];
				int nx = now.x2 + horizontal_x[i];
				if (ny <= 0 || nx <= 0 || ny > n || nx > n)continue;
				if (map[ny][nx] != 0)continue;
				if (i == 1 && (map[ny - 1][nx] != 0 || map[ny][nx - 1] != 0)) continue;

				q.push({ now.y2, now.x2, ny, nx });
			}

		}
		//세로
		else if (now.x2 - now.x1 == 0) {
			for (int i = 0; i < 2; i++) {
				int ny = now.y2 + vertical_y[i];
				int nx = now.x2 + vertical_x[i];
				if (ny <= 0 || nx <= 0 || ny > n || nx > n)continue;
				if (map[ny][nx] != 0)continue;
				if (i == 1 && (map[ny - 1][nx] != 0 || map[ny][nx - 1] != 0)) continue;


				q.push({ now.y2, now.x2, ny, nx });
			}
		}
		//대각선
		else if(now.x2 - now.x1 != 0 && now.y2 - now.y1 != 0) {
			for (int i = 0; i < 3; i++) {
				int ny = now.y2 + incline_y[i];
				int nx = now.x2 + incline_x[i];
				if (ny <= 0 || nx <= 0 || ny > n || nx > n)continue;
				if (map[ny][nx] != 0)continue;
				if (i == 2 && (map[ny - 1][nx] != 0 || map[ny][nx - 1] != 0)) continue;


				q.push({ now.y2, now.x2, ny, nx });
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	go();
	cout << cnt;
}