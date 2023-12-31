#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, arr[1000]={0};
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int dp[1000]={0};
    dp[0]=1;

    int answer=1;
    for(int i = 1; i<n; i++)
    {
        dp[i]=1; // 자기 자신만 있는 경우 {arr[i]}
        for(int j = 0; j<i; j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        answer=max(answer, dp[i]);
    }

    cout<<answer;
    return 0;
}