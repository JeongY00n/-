#include<iostream>
#include<vector>
using namespace std;

int N,D;
vector<pair<int,int>> v[10001];

void init(){
    cin>>N>>D;
    for(int i = 0; i<N; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        v[from].push_back({to,cost});
    }

}
void solution(){
    int dp[10001];
    for(int i = 0; i<=10000; i++)
        dp[i]=i;
        
        
    for(int i = 0; i<=D; i++)
    {
        // 지름길로 간 경우와 그냥 고속도로를 탔을 때의 이동 거리를 비교하여 최솟값으로 갱신
        if(i!=0)
            dp[i]=min(dp[i],dp[i-1]+1);

        if(v[i].empty())continue;
        // 지름길을 탄 경우
        for(int j = 0; j<v[i].size(); j++)
        {
            int to=v[i][j].first;
            int cost=v[i][j].second;

            dp[to]=min(dp[to], dp[i]+cost);
        }
        
    }
    cout<<dp[D];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}