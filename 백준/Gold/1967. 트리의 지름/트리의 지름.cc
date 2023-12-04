#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    각 간선에 cost가 주어지고 
    두 노드를 연결하는 경로의 최댓값을 구해라
    최하단의 자식노드들에 대해서 조합 계산하기
    루트에서 가장 먼 노드와 그 노드에서 가장 먼 노드의 경로 cost 합

    내 아이디어
    - 최하단의 자식노드와 부모와 연결된 간선의 cost에 대해 우선순위큐를 사용하여
    가장 cost가 큰 것을 우선순위에 두고 올라가는 형식  

    각 노드까지의 최대 가중와 두 경로의 합을 저장 그리고 정답을 계속 갱신

*/

struct NODE{
    int to, cost;
};
int n;
vector<NODE> node[10001];
void init(){
    cin>>n;
    for(int i = 0; i<n-1; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        node[from].push_back({to, cost});
        node[to].push_back({from, cost});
    }
}
int nodeid, maxicost;
void solution(int start){
    int visited[10001]={0};
    queue<pair<int,int>> q;

    q.push({start,0});
    visited[start]=1;
    maxicost=0;

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        int from = now.first;
        int nowcost = now.second;

        for(int i = 0; i<node[from].size(); i++)
        {
            int to = node[from][i].to;
            int cost = node[from][i].cost;

            if(visited[to]==1)continue;
            visited[to]=1;

            if(maxicost<nowcost+cost)
            {
                maxicost=nowcost+cost;
                nodeid=to;
            }
            q.push({to, nowcost+cost});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    
    solution(1);
    solution(nodeid);

    cout<<maxicost;
    return 0;
}