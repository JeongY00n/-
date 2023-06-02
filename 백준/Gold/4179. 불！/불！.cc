#include <iostream>
#include <queue>
using namespace std;
int R, C;
char graph[1000][1000];
bool visited[1000][1000];
int fire_map[1000][1000];
vector<pair<int, int>> fire;
int groupCnt = 0;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void make_fireMap() {
	vector<queue<pair<int, int>>> fireQ(fire.size());

	for (int i = 0; i < fire.size(); i++) {
		fireQ[i].push({ fire[i].first,fire[i].second });
	}

	for (int f = 0; f < fireQ.size(); f++) {
		while(!fireQ[f].empty()) {
			int cur_fireR = fireQ[f].front().first;
			int cur_fireC = fireQ[f].front().second;
			fireQ[f].pop();

			for (int i = 0; i < 4; i++) {
				int	next_fireR = cur_fireR + dir[i][0];
				int	next_fireC = cur_fireC + dir[i][1];
				if (next_fireR >= 0 && next_fireR < R && next_fireC >= 0 && next_fireC < C && graph[next_fireR][next_fireC] != '#') {
					if (fire_map[cur_fireR][cur_fireC] + 1 < fire_map[next_fireR][next_fireC]) {
						fireQ[f].push({ next_fireR,next_fireC });
						fire_map[next_fireR][next_fireC] = fire_map[cur_fireR][cur_fireC] + 1;
					}
				}
				
			}
		}
	}
}
void move(int startR, int startC) {
	queue<pair<pair<int,int>,int>> startQ;
	
	startQ.push({ { startR,startC },0 });
	

	while (!startQ.empty()) {

		int cur_startR = startQ.front().first.first;
		int cur_startC = startQ.front().first.second;
		int cnt = startQ.front().second;

		if (cur_startR == 0 || cur_startR == R-1 || cur_startC == 0 || cur_startC == C-1) {//나갔을 때
			cout << cnt + 1;
			return;
		}
		startQ.pop();
		for (int i = 0; i < 4; i++) {
			int next_startR = cur_startR + dir[i][0];
			int next_startC = cur_startC + dir[i][1];
			if (next_startR >= 0 && next_startR < R&&next_startC >= 0 && next_startC < C) {
				if (fire_map[next_startR][next_startC] > cnt + 1 && graph[next_startR][next_startC] == '.') {
					if (!visited[next_startR][next_startC]) {
						startQ.push({ { next_startR,next_startC },cnt + 1 });
						visited[next_startR][next_startC] = true;
					}
				}
			}

		}
	}


	cout << "IMPOSSIBLE";
	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	
	pair<int,int>start;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char ch;
			cin >> ch;
			if (ch == 'F') {
				fire.push_back({ i,j });
				graph[i][j] = 'F';
				fire_map[i][j] = 0;
				
			}
			else if (ch == 'J') {
				start = { i,j };
				graph[i][j] = '.';
				fire_map[i][j] = 987654321;
			}
			else {
				graph[i][j] = ch;
				fire_map[i][j] = 987654321;
			}
		}
	}
	make_fireMap();
	move(start.first, start.second);
	return 0;
}