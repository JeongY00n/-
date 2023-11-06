#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    최소비용 => 다익스트라
*/

struct NODE{
    int to, cost;

    // cost에 대해 오름차순으로 정렬
    bool operator<(const NODE&other) const{
        if(cost<other.cost)return false;
        if(cost>other.cost)return true;

        return false;
    }
};
int N,M;
vector<NODE> n[1001];
int startnode, endnode; 
void init(){
    cin>>N>>M;

    for(int i = 0; i<M; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;

        n[from].push_back({to, cost});
    }
    cin>>startnode>>endnode;
}

void dijkstra(){
    if(startnode==endnode)
    {
        cout<<0;
        return;
    }
    priority_queue<NODE> pq;
    
    int visited[1001]={0};
    for(int i = 1; i<=N; i++)
        visited[i]=2e9;
    visited[startnode]=0;

    for(int i = 0; i<n[startnode].size(); i++)
    {
        pq.push({n[startnode][i].to, n[startnode][i].cost});
        visited[n[startnode][i].to]=n[startnode][i].cost;
    }

    while(!pq.empty()){
        NODE now = pq.top();
        pq.pop();
        
        int from = now.to;
        int cost = now.cost;

        if(from == endnode)
        {
            cout<<cost;
            return;
        }

        for(int i = 0; i<n[from].size(); i++)
        {
            int to = n[from][i].to;
            
            if(visited[to]<=cost+n[from][i].cost)continue;

            visited[to]=cost+n[from][i].cost;
            pq.push({to, cost+n[from][i].cost});
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dijkstra();

    return 0;
}