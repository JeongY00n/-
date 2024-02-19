#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

/*
    게임 도중 점프하는 총 거리의 최솟값
    다음 숫자의 거리를 비교하고 
*/

struct INFO{
    int y,x,cost;

    // 오름차순
    bool operator<(const INFO&other) const{
        return cost>other.cost;
    }
};
int N,K, map[50][50];
int answer=1e9, flag=0;
int dp[50][50]; // 최단 거리
vector<pair<int,int>> coord[2500];
void init(){
    priority_queue<INFO> pq;
    cin>>N>>K;

    // 초기화
    for(int i = 1; i<=K; i++)
        coord[i].clear();
    fill(&dp[0][0], &dp[49][50], 1e9);
    answer=1e9;
    flag=0;

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin>>map[i][j];
            coord[map[i][j]].push_back({i,j});
            if(map[i][j]==K)
                dp[i][j]=0;
        }    
    }
    for(int i = 1; i<=K; i++)
    {
        if(coord[i].empty())
        {
            flag=1;
            return;
        }
    }
}
void solution(int n, int y, int x){
    if(n==K+1)
    {
        return;
    }
    for(int i = 0; i<coord[n].size(); i++)
    {
        int ny=coord[n][i].first;
        int nx=coord[n][i].second;
        
        // 값이 저장되어 있으면 어차피 해당 위치의 최솟값이 저장되어 있기 때문에 더 진행하지 않고
        // 현재 위치와의 거리를 더해서 dp에 저장
        if(dp[ny][nx]!=1e9)
        {
            if(dp[y][x]>dp[ny][nx]+abs(y-ny)+abs(x-nx)){
                dp[y][x]=dp[ny][nx]+abs(y-ny)+abs(x-nx);
            }
               continue;

        }

        solution(n+1, ny, nx);

        if(dp[y][x]>dp[ny][nx]+abs(y-ny)+abs(x-nx))
            dp[y][x]=dp[ny][nx]+abs(y-ny)+abs(x-nx);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    for(int tc=1; tc<=T; tc++)
    {
        init();
        if(flag==1)
        {
            cout<<"#"<<tc<<" "<<-1<<"\n";
            continue;
        }
        for(int i = 0; i<coord[1].size(); i++)
        {
            int y=coord[1][i].first;
            int x=coord[1][i].second;
            solution(2,y,x);
            answer = min(answer, dp[y][x]);
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }

    return 0;
}