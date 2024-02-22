#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

/*
4개의 방향을 다 돌았는지 확인

*/
int n,m;
int answer=0;
char map[1001][1001];
int dp[1001][1001];
void init(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            cin>>map[i][j]; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(map[i][j]=='1')
            {
                dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                answer=max(answer,dp[i][j]);
            }
        }
    }

    cout<<answer*answer;
    return 0;
}