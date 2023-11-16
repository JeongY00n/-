#include<iostream>

using namespace std;

/*
    1,2,3을 사용하여 해당 숫자를 만들 수 있는 경우의 수 계산
    순서도 고려해주어야함
    dp[1]=1
    dp[2]=2 (1+1, 2)
    dp[3]=4 (1+1+1, 1+2, 2+1, 3)
    dp[a] = dp[a-1]+dp[a-2]+dp[a-3]

    */
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;

    for(int tc=1; tc<=T; tc++)
    {
        int n;
        cin>>n;
        
        int dp[11]={0};
        dp[1]=1; dp[2]=2; dp[3]=4;
        for(int i = 4; i<=n; i++)
        {
            dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
        }
        cout<<dp[n]<<"\n";
    }

    return 0;
}