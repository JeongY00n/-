#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
/*
    통신하기 위한 최소거리
    로봇에서 다른 방까지 이동하는 최단 거리 저장
*/

struct EDGE{
    int to, cost;
};

int n, rb1, rb2;
vector<EDGE> edge[100001];
int min_cost[100001][2], answer = 2e9;

void init(){
    cin>>n>>rb1>>rb2;
    for(int i = 0; i<n-1; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        edge[from].push_back({to, cost});
        edge[to].push_back({from, cost});
    }
    fill(&min_cost[0][0], &min_cost[100000][1], 2e9);
}

void savecost(int rb, int idx){
    queue<EDGE> q;
    q.push({rb, 0});

    min_cost[rb][idx]=0;

    while(!q.empty()){
        EDGE now = q.front();
        q.pop();

        int from = now.to;
        for(int i = 0; i<edge[from].size(); i++){
            int to = edge[from][i].to;
            int cost = edge[from][i].cost;

            if(min_cost[to][idx]>min_cost[from][idx]+cost)
            {
                min_cost[to][idx] = min_cost[from][idx]+cost;
                q.push({to, min_cost[to][idx]});
            }
            
        }
    }
}

void solution(){
    
    for(int i = 1; i<=n; i++)
    {
        int sum = min_cost[i][0]+min_cost[i][1];
        // 로봇에서 가까운 방 찾기
        int rb1_min = 2e9, min_idx1=0;
        int rb2_min = 2e9, min_idx2=0;
        for(int j = 0; j<edge[i].size(); j++)
        {
            if(rb1_min>min_cost[edge[i][j].to][0])
            {
                rb1_min=min_cost[edge[i][j].to][0];
                min_idx1=j;
            }

            if(rb2_min>min_cost[edge[i][j].to][1])
            {
                rb2_min=min_cost[edge[i][j].to][1];
                min_idx2=j;
            }
            
        }
        answer = min(answer, sum-edge[i][min_idx1].cost);
        answer = min(answer, sum-edge[i][min_idx2].cost);
    }
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    savecost(rb1,0);
    savecost(rb2,1);
    if(n==1 || rb1 == rb2)
        cout<<0;
    else
        solution();

    return 0;
}