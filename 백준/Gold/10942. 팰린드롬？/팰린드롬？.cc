#include<iostream>

using namespace std;

/*
    S와 E가 주어지면 
    * dp 활용?!
*/

int n,num[2002],m;
int S,E;
int dp[2002][2002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; i++)
        cin>>num[i];

    for(int i = 1; i<=n; i++)
    {
        dp[i][i]=1;
        if(num[i]==num[i+1])dp[i][i+1]=1;
    }

    for(int i = 2; i<n; i++) // (3~n)길이
    {
        for(int j = 1; j<=n-i; j++) // 구간
        {
            if(num[j]==num[j+i] && dp[j+1][j+i-1]) dp[j][j+i]=1;
        }
    }

    cin>>m;
    for(int i = 0; i<m; i++)
    {
        cin>>S>>E;
        cout<<dp[S][E]<<"\n";
    }

    return 0;
}