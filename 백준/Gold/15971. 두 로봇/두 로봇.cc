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
    int to, cost, maxi;
};

int n, rb1, rb2;
vector<EDGE> edge[100001];
int min_cost[100001];
void init(){
    cin>>n>>rb1>>rb2;
    for(int i = 0; i<n-1; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        edge[from].push_back({to, cost});
        edge[to].push_back({from, cost});
    }
    fill(min_cost, min_cost+n+1, 2e9);
}

void solution(){
    queue<EDGE> q;
    q.push({rb1,0,0});

    min_cost[rb1]=0;
    while(!q.empty()){
        EDGE now = q.front();
        q.pop();

        int from = now.to;
        int maxi = now.maxi;

        if(from == rb2)
        {
            cout<<min_cost[rb2]-now.maxi;
            return;
        }
        
        for(int i = 0; i<edge[from].size(); i++)
        {
            int to = edge[from][i].to;
            int cost = edge[from][i].cost;
            
            if(min_cost[to] > min_cost[from]+cost){
                min_cost[to]=min_cost[from]+cost;
                maxi = max(maxi, cost);
                q.push({to, min_cost[to],maxi});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    if(n==1 || rb1 == rb2)
        cout<<0;
    else
        solution();

    return 0;
}