#include<iostream>

using namespace std;

/*
    최대 K만큼의 무게에 최대 가치를 챙기면서 짐을 챙기기
    짐을 선택하는 경우 선택하지 않는 경우
*/

int n,k; // 물건개수, 최대무게
int dp[101][100001]={0};
int W[100001], V[100001];
void init(){
    cin>>n>>k;
    for(int i = 1; i<=n; i++)
        cin>>W[i]>>V[i];
}

void DP(){
    for(int w=1; w<=k; w++)
    {
        for(int i=1; i<=n; i++)
        {
            // 담을 수 없는 경우
            if(W[i]>w)
                dp[i][w]=dp[i-1][w];

            // 담을 수 있는 경우
            else
                dp[i][w]=max(dp[i-1][w-W[i]]+V[i], dp[i-1][w]);
        }
    }
    
    cout<<dp[n][k];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    DP();

    return 0;

}