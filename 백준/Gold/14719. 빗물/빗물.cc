#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int H, W;
vector <int> v;
int wall[501] = {0,};
int firstWall;	// 처음으로 벽이 들어온 인덱스 기록
int cnt = 0;


void init() {
	cin >> H >> W;
	int flag = 0;
	for (int i = 0; i < W; i++) {
		int a;
		cin >> a;
		v.push_back(a);

		if (a != 0) {	// 일단 벽이 있는 인덱스 기록
			if (flag == 0) {
				firstWall = i;
				flag = 1;
			}
		}
	}
	memset(wall, -1, sizeof(wall));
	for (int i = 1; i <= v[firstWall]; i++) wall[i] = firstWall;
}



int calc() {
	for (int i = firstWall; i < W-1; i++) {
		for (int j = 1; j <= v[i]; j++) {
			wall[j] = i;
		}
		if (v[i] < v[i + 1]) {	// 내 뒤가 나보다 높으면 빗물이 고인다.
			for (int j = 1; j <= v[i + 1]; j++) {	// 다음 높이까지
				if (wall[j] == -1) continue;
				cnt += (i - wall[j]);
			}
		}
	}
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	int ans = calc();
	cout << ans;

	return 0;
}