#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    int num[1000]={0};
    for(int i = 0; i<n; i++)
        cin>>num[i];
    
    // [증가중 감소중][숫자배열의 인덱스]=수열의 길이
    // 증가중 0, 감소중 1
    int dp[2][1000]={0};
    fill(&dp[0][0], &dp[1][1000], 1);

    int answer=1;
    for(int i = 1; i<n; i++)
    {
        int idx=i-1;
        
        while(idx>=0){
            // 증가
            if(num[i]>num[idx])
            {
                dp[0][i]=max(dp[0][i],dp[0][idx] +1);
            }

            // 감소
            // 증가하다가 감소하는 경우, 그냥 계속 감소중인 경우
            if(num[i]<num[idx])
            {
                dp[1][i]=max(dp[1][i], max(dp[0][idx], dp[1][idx])+1);
            }

            idx--;
        }
        answer=max(answer,max(dp[0][i], dp[1][i]));

        // cout<<"오"<<" "<<"내\n";
        // cout<<dp[0][i]<<","<<dp[1][i]<<"\n";    
    }

    cout<<answer;
    return 0;
}