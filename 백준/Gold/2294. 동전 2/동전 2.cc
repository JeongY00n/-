#include<iostream>

using namespace std;

/*
    동전을 최소한으로 사용해서 k원 만들기
    동전갯수 저장
*/

int n,k;
int coin[101], dp[10001];


void init(){
    cin>>n>>k;
    for(int i = 1; i<=n; i++)
        cin>>coin[i];
}

void DP(){
    
    // v=0에 대해서는 나중에 v==coin[i]인 부분에서 dp에 1을 저장해주어야하기 때문에 2e9로 초기화하지 않는다
    // 0으로 내버려둠
    for(int v=1; v<=k; v++)
        dp[v]=2e9;

    for(int v=1; v<=k; v++)
    {
        for(int i = 1; i<=n; i++)
        {
            if(v<coin[i])
                continue;
            else
                dp[v] = min(dp[v], dp[v-coin[i]]+1);
        }
    }

    int answer=0;
    if(dp[k]==2e9)
        answer=-1;
    else
        answer=dp[k];
        
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    DP();

    return 0;
}