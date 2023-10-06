#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int dp[201][201]={0};
    int mod = 1000000000;
    // i개로 0만들기
    for(int i = 0; i<=k; i++)
        dp[i][0]=1;

    // i개로 j만들기
    for(int i = 1; i<=k; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000000;
        }
    }
    cout<<dp[k][n];

    return 0;
}