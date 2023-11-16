#include<iostream>

using namespace std;

/*
    1인 경우 계산안해도 됨 dp[1]=0;
    주어진 숫자에 대해 2로 나눌 수 있는지 3으로 나눌 수 있는지 확인 필요
    연산 횟수를 기록
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    int dp[1000001]={0};
    //fill(dp, dp+1000001, 2e9);

    dp[1]=0;
    for(int i = 2; i<=n; i++)
    {
        dp[i]=dp[i-1]+1;
        if(i%2==0)
            dp[i]=min(dp[i/2]+1, dp[i]);
        if(i%3==0)
            dp[i]=min(dp[i/3]+1, dp[i]);
    }
    cout<<dp[n];
    return 0;
}