#include<iostream>
#include<algorithm>
using namespace std;

/*
    갈 수 없는 경로를 구분하기 위해서 dp를 -1로 초기화 해줄 필요가 있음
*/
int M,N;
int map[500][500];
int dp[500][500];
void init(){
    cin>>M>>N;
    for(int i = 0; i<M; i++)
        for(int j = 0; j<N; j++)
            cin>>map[i][j];
    fill(&dp[0][0], &dp[499][500], -1);
    dp[M-1][N-1]=1;
}

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
void solution(int y, int x){
    // 지나간적 있는 위치에 대해서는 더이상 진행하지 않음
    if(dp[y][x]!=-1)
        return;

    // 지나갔음을 표시하기
    dp[y][x]=0;

    for(int i = 0; i<4; i++)
    {
        int ny = y+fy[i];
        int nx = x+fx[i];

        if(ny<0||nx<0||ny>=M||nx>=N)continue;
        if(map[y][x]<=map[ny][nx])continue;

        if(dp[ny][nx]>0)
        {
            dp[y][x]+=dp[ny][nx];
            continue;
        }

        solution(ny,nx);
        dp[y][x]+=dp[ny][nx];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution(0,0);
    cout<<dp[0][0];
    return 0;
}