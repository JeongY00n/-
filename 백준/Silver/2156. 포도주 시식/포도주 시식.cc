#include<iostream>

using namespace std;

/*
    연속된 갯수를 확인하기 위해 2차원 배열 생성
*/

int n, wine[10001], dp[10001][3];
int answer;
void init(){
    cin>>n;
    for(int i = 1; i<=n; i++)
        cin>>wine[i];
}

void solution(){
    dp[1][1]=wine[1];
    dp[2][1]=wine[2];
    answer = max(dp[1][1],answer);
    
    for(int i = 2; i<=n; i++)
    {
        // 연속되지 않은 경우
        for(int j = i-3; j<i-1; j++)
        {
            if(j<=0)continue;
            for(int s = 1; s<=2; s++)
            {
                dp[i][1] = max(dp[i][1], dp[j][s]+wine[i]);
            }
        }
        dp[i][2] = dp[i-1][1]+wine[i];

        //cout<<dp[i][1]<<" "<<dp[i][2]<<" \n";
        answer = max(answer, max(dp[i][1], dp[i][2]));
        
    }
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}