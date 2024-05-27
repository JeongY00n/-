#include<iostream>

using namespace std;

int n, map[501][501];
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin>>map[i][j];
}
int dy[]={-1,1,0,0}, dx[]={0,0,-1,1};
int dp[501][501], answer;
void dfs(int y, int x, int cnt){
    //cout<<y<<","<<x<<","<<map[y][x]<<","<<cnt<<"\n";
    if(dp[y][x])return;

    for(int i = 0; i<4; i++)
    {
        int ny = y+dy[i], nx = x+dx[i];

        if(ny<0||nx<0||ny>=n||nx>=n)continue;
        // 대나무가 더 많이 있는 지역으로 이동
        if(map[ny][nx]<=map[y][x])continue;

        dfs(ny,nx,cnt+1);

        dp[y][x]=max(dp[y][x], dp[ny][nx]+1);
    }
    if(!dp[y][x])
        dp[y][x]=1;
    answer=max(answer,dp[y][x]);
}
void solution(){
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            dfs(i,j,0);
        }
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}