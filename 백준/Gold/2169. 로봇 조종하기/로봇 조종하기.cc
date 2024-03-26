#include<iostream>
#include<algorithm>

using namespace std;


int N,M;
int map[1001][1001];
void init(){
    cin>>N>>M;
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=M; j++)
            cin>>map[i][j];
}

// 오른쪽방향, 왼쪽방향으로 이동시켰을 때의 최대값 저장하기 위함
int temp[2][1002][1002]={0};
int dp[1001][1001]={0};
void solution(){

    // 모서리 -1e9로 초기화
    for(int i = 0; i<=N+1; i++)
    {
        temp[0][i][0]=-1e9;
        temp[1][i][M+1]=-1e9;
    }
    for(int i = 0; i<=M+1; i++)
    {
        temp[0][0][i]=-1e9;
        temp[1][N+1][i]=-1e9;
    }

    for(int i = 1; i<=M; i++)
        dp[1][i]=dp[1][i-1]+map[1][i];
    

    for(int j = 2; j<=N; j++)
    {
        // 오른쪽 방향으로 이동시키면서 가치를 더할 때
        // 1에서 i-1까지 더해진 값에 i위치 값을 더한 것과
        // 한줄 윗칸의 dp값에 i위치의 값을 더한 것을 비교
        // 더 큰 것 선택
        for(int i = 1; i<=M; i++)
        {
            temp[0][j][i]=max(dp[j-1][i], temp[0][j][i-1])+map[j][i];
        }
        // 왼쪽 방향으로
        for(int i = M; i>=1; i--)
        {
            temp[1][j][i]=max(dp[j-1][i], temp[1][j][i+1])+map[j][i];
        }

        for(int i = 1; i<=M; i++)
            dp[j][i]=max(temp[0][j][i], temp[1][j][i]);
    }
    
    cout<<dp[N][M];
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}