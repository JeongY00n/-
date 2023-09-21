#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    반드시 거쳐야하는 두 정점
*/
struct Node{
    int to;
    long long cost;

    bool operator<(const Node& other)const{
        return cost > other.cost;
    }
};
int n,e,v1,v2;
vector<Node> node[801];
long long visited[801];
void init(){
    cin>>n>>e;
    for(int i = 0; i<e; i++)
    {
        int from, to;
        long long cost;
        cin>>from>>to>>cost;
        node[from].push_back({to, cost});
        node[to].push_back({from, cost});
    }
    cin>>v1>>v2;
}
void solution(int start){
    priority_queue<Node> q;
    fill(&visited[0], &visited[801], 4e9);
    visited[start]=0;
    q.push({start,0});

    while(!q.empty()){
        Node now = q.top();
        q.pop();

        int from = now.to;
        if(visited[from]<now.cost)continue;

        for(int i = 0; i<node[from].size(); i++){
            int to = node[from][i].to;
            long long cost = node[from][i].cost;

            if(visited[to] <= now.cost+cost)continue;

            visited[to]=now.cost+cost;
            q.push({to, visited[to]});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    long long first1, first2, second, third1, third2;
    solution(1);
    first1 = visited[v1];
    first2 = visited[v2];
    solution(v1);
    second = visited[v2];
    solution(n);
    third1 = visited[v1];
    third2 = visited[v2];
    
    long long cost1 = min(first1+third2, first2+third1);

    if(cost1>=4e9||second>=4e9)
        cout<<"-1";
    else
        cout<<cost1+second;

    return 0;
}