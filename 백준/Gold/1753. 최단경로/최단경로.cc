#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    bfs로 경로 탐색
*/

struct Edge{
    int to, cost;
};
struct cmp{
    bool operator()(Edge a, Edge b){
        if(a.cost < b.cost) return false;
        if(a.cost > b.cost) return true;
        return false;
    }
};

int v,e;
int start;
int calc[20001];
vector<Edge> edge[20001];
void init(){
    cin>>v>>e;
    cin>>start;
    for(int i = 0; i<e; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        edge[from].push_back({to, cost});
    }
    fill(calc, calc+20001, 2e9);
}
void dijkstra(){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({start, 0});
    calc[start]=0;

    while(!pq.empty()){
        Edge now = pq.top();
        pq.pop();

        int from = now.to;

        for(int i = 0; i<edge[from].size(); i++)
        {
            int to = edge[from][i].to;
            int cost = edge[from][i].cost;
            if(calc[to]>calc[from]+cost)
            {
                calc[to]=calc[from]+cost;
                pq.push({to, calc[to]});
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dijkstra();
    for(int i = 1; i<=v; i++)
    {
        if(calc[i]==2e9)
            cout<<"INF\n";
        else
            cout<<calc[i]<<"\n";
    }
    return 0;
}