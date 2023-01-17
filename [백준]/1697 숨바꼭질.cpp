#include <iostream>
#include <queue>
using namespace std;

struct Status {
	int coord, time;
};
int N, K;
int ans = 0;
int visited[100010];

void init() {
	cin >> N >> K;
}

void BFS() {
	queue<Status> q;
	q.push({ N , 0 });
	while (!q.empty()) {
		Status s = q.front();
		q.pop();

		int locate= s.coord;
		int time = s.time;

		if (locate== K) {
			ans = time;
			return;
		}

		if (locate+ 1 <= K && visited[locate+ 1] == 0)
		{
			q.push({ locate+ 1, time + 1});
			visited[locate+ 1] = 1;
		}
		if (locate- 1 >= 0 && visited[locate- 1] == 0)
		{
			q.push({locate- 1, time + 1});
			visited[locate- 1] = 1;
		}
		if (2 * locate<= K+1 && visited[2 * locate] == 0)
		{
			q.push({2 * locate, time + 1 });
			visited[2 * locate] = 1;
		}
		
	}

}
int main() {
	init();
	BFS();
	cout << ans;
}