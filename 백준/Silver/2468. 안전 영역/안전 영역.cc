#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

/*
물에 잠기지 않는 안전한 영역의 최대 개수
최저 최고 높이를 파악 for문
비에 잠김 여부를 알 수 있는 새로운 map 생성
bfs 사용하기(같은 영역 파악)
영역 갯수를 저장해서 최댓값 파악
*/

struct Coord {
    int y, x;
};

int N, map[101][101], copy_map[101][101];
int maxi = 0, mini = 2e9;
int answer = 0;

void init() {
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] > maxi) maxi = map[i][j];
            if (map[i][j] < mini) mini = map[i][j];
        }
    }
}

void copyMAP(int height) {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] <= height)
                copy_map[i][j] = 0;
            else
                copy_map[i][j] = map[i][j];
        }
    }
}

int visited[101][101] = { 0 };
int fy[] = { 0,0,-1,1};
int fx[] = { -1,1,0,0 };
void bfs(int y, int x) {
    queue<Coord> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (!q.empty()) {
        Coord now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + fy[i];
            int nx = now.x + fx[i];
            
            // map범위를 벗어난 경우
            // 이미 지나간 적이 있는 경우
            // 물에 잠긴 지역인 경우
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
            if (visited[ny][nx] == 1)continue;
            if (copy_map[ny][nx] == 0)continue;
            visited[ny][nx] = 1;
            q.push({ ny,nx });
        }

    }
}

void solution() {
    // 지역 높이는 1 ~ 100
    for (int i = 0; i <= maxi; i++)
    {
        copyMAP(i);
        int cnt = 0;
        memset(visited, 0, sizeof(visited));

        for (int col = 0; col < N; col++)
        {
            for (int row = 0; row < N; row++)
            {
                if (copy_map[col][row] > 0 && visited[col][row] == 0)
                {
                    bfs(col, row);
                    cnt++;
                }
            }
        }
        if (answer < cnt)
            answer = cnt;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout << answer;

    return 0;
}