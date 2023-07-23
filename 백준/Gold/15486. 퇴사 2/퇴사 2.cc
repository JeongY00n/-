#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

/*
상담을 적절하게 했을 때, 백준이가 얻을 수 있는 최대 수익은?
n일 이후에도 필요한 상담은 불가
해당 날짜까지 번 소득 저장
*/

int n, answer=0;
int timetime[1500001], pay[1500001];
int dp[1500001];

void init(){
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        cin>>timetime[i]>>pay[i];
    }
}

void solution(){

    int cur_maxi=0;
    for(int i = 1; i<=n; i++)
    {
        dp[i+timetime[i]]=max(dp[i+timetime[i]], dp[i]+pay[i]);
        dp[i + 1]=max(dp[i+1], dp[i]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<dp[n+1];

    return 0;
}