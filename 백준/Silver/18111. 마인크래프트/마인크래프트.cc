#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, B;
int map[501][501];
int mini=2e9, maxi = 0;
int mini_cnt = 0, maxi_cnt = 0;
void input() {
	cin >> N >> M >> B;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];
			if (mini > map[y][x])
			{
				mini_cnt = 0;
				mini = map[y][x];
				mini_cnt++;
			}
			if (maxi < map[y][x])
			{
				maxi_cnt = 0;
				maxi = map[y][x];
				maxi_cnt++;
			}
			if (mini == map[y][x])
				mini_cnt++;
			if (maxi == map[y][x])
				maxi_cnt++;
		}
	}
}


int main() {
	input();
	int ans = 2e9, h=0;
	int block = B;
	for (int i = mini; i <= maxi; i++) {
		int sum = 0;
		block = B;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{

				if (i > map[y][x]) // 블록을 쌓아야하는 경우
				{
					sum += i - map[y][x];
					block -= i - map[y][x];
				}
				if (i < map[y][x]) // 블록을 빼야하는 경우
				{
					sum += 2 * (map[y][x] - i);
					block += map[y][x] - i;
				}
				
			}
			if (sum >= ans) continue;
		}
		if (ans >= sum && block >=0)
		{
			ans = sum;
			h = i;
		}
	}

	cout << ans << " " << h;

	return 0;
}