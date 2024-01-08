#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

/*
    다익스트라
    플로이드워셜 => 시간초과 1000*1000*1000 => 10억 (시간초과) 
    1초 = n이 1억정도의 시간
*/

struct Edge{
    int to, cost;

    bool operator<(const Edge&other)const{
        if(cost<other.cost) return false;
        if(cost>other.cost) return true;

        return false;
    }
};

int n,m;
vector<Edge> bus[1001];
int s,e;

void init(){
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        bus[from].push_back({to,cost});
    }
    cin>>s>>e;
}

void dijkstra(){

    priority_queue<Edge> q;
    q.push({s,0});

    queue<int> path[1001];
    path[s].push(s);

    int visited[1001];
    fill(visited, visited+1001, 2e9);
    visited[s]=0;

    int answer=2e9;

    while(!q.empty()){
        Edge now = q.top();
        q.pop();

        int from = now.to;
        int ncost = now.cost;

        if(from == e) 
        {
            answer = ncost;
            break;
        }

        for(int i = 0; i<bus[from].size(); i++)
        {
            int to = bus[from][i].to;
            int cost = bus[from][i].cost;

            if(from==to)continue; // 동일 도시로 이동하는 사이클에 대해 처리하기
            if(visited[to]<=ncost+cost)continue;
            visited[to]=ncost+cost;

            path[to]=path[from];
            path[to].push(to);

            q.push({to, cost+ncost});
        }

    }

    cout<<answer<<"\n";
    cout<<path[e].size()<<"\n";

    while(!path[e].empty())
    {
        cout<<path[e].front()<<" ";
        path[e].pop();
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