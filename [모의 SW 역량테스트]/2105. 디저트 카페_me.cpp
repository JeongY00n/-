#include <iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Coord {
	int row;
	int col;
};

int N;
int map[30][30];
// 들렸는가만 기록하지 않고 -> 몇 번째로 들렸는가? 도 기록
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
}

int DAT[101] = { 0 };
int visited[30][30] = { 0 };
int ans = -1;
//dfs 모든 경우의 수를 확인할 수 있다
void dfs(Coord now, int cnt, Coord start) {

	int row = now.row;
	int col = now.col;
	
	if (row == start.row && col == start.col && visited[row][col]!=0) 
	{
		ans = max(ans, visited[row][col]);
		visited[row][col] = 0;

		return;
	}
	
	//우하 좌하 좌상 우상
	int dr[] = { 1,1,-1,-1 };
	int dc[] = { 1,-1,-1,1 };
	for (int i = 0; i < 2; i++) {
		int nr = row + dr[cnt + i];
		int nc = col + dc[cnt + i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
		if (cnt + i >= 4) continue;
		if (DAT[map[nr][nc]] != 0)continue;
		DAT[map[nr][nc]] = 1;
		if (visited[nr][nc] != 0)continue;
		visited[nr][nc] = visited[row][col] + 1;

		dfs({ nr,nc }, cnt + i, start);

		visited[nr][nc] = 0;
		DAT[map[nr][nc]] = 0;
	}

}

int solution() {
	ans = -1;
	for (int row = 0; row < N; row++) 
		for (int col = 0; col < N; col++)
		{
			Coord st = { row, col };
			dfs(st, 0, st);
		}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}
	return 0;
}
