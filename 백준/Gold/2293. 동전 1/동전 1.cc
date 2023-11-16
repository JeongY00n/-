#include<iostream>
#include<vector>
using namespace std;

/*
    목표값을 만들기 위해 사용되는 동전의 종류
    dp[0] = 1
    dp[1] = 1
    가지고 있는 동전으로 해당 숫자를 만들 수 있는 경우의 수
*/
int n, k;
int cost[100], dp[10001];
void init(){
    cin>>n>>k;
    for(int i = 0; i<n; i++)
        cin>>cost[i];
}
void solution(){
    dp[0]=1;
    // 코인의 idx
    for(int c = 0; c<n; c++)
    {
        // dp 계산
        for(int i = cost[c]; i<=k; i++)
        {
            dp[i] = dp[i]+dp[i-cost[c]];
        }
    }
    cout<<dp[k];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}