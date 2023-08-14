#include<iostream>
#include<queue>
using namespace std;

/*
    dfs로 현재 높이보다 더 낮은 지점에 대해서만 이동
    dp사용
    해당 위치에서 목적지까지 갈 수 있는 경로의 수를 저장
    상하좌우
    이동 가능한 모든 경로의 수
*/

struct Coord{
    int y,x;
};

int m,n,map[500][500];
int answer;
int dp[500][500];
void init(){
    cin>>m>>n;
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
            cin>>map[i][j];

    fill(&dp[0][0], &dp[499][499], -1);
    dp[m-1][n-1]=1;
}

int fy[] = {-1,1,0,0};
int fx[] = {0,0,-1,1};

void dfs(int y, int x){
    
    if(dp[y][x]!=-1)
    {
        return;
    }

    dp[y][x]=0;

    for(int i = 0; i<4; i++)
    {
        int ny = y + fy[i];
        int nx = x + fx[i];

        if(ny<0||nx<0||ny>=m||nx>=n)continue;
        if(map[ny][nx]>=map[y][x])continue;



        // 이전에 이미 지나간 적이 있는 경우
        // 저장된 값(경로 수) 더해줌
        if(dp[ny][nx]>0){
            dp[y][x]+=dp[ny][nx];
            continue;
        }
        
        dfs(ny,nx);        
        dp[y][x]+=dp[ny][nx];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(0,0);
    cout<<dp[0][0];
    return 0;
}