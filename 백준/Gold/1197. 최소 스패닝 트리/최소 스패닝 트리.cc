#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
    cost가 가장 작은 순으로 간선 정렬
*/

struct EDGE{
    int to, from, cost;

    // 오름차순으로 정렬
    bool operator<(const EDGE&other) const{
        if(cost<other.cost)return false;
        if(cost>other.cost)return true;

        return false;
    }
};
int V,E;
priority_queue<EDGE> pq;

void init(){
    cin>>V>>E;
    for(int i = 0; i<E; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        pq.push({from,to,cost});
    }
}

int getParent(int parent[], int a){
    if(parent[a]==a) return a;
    return parent[a] = getParent(parent, parent[a]);
}
void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a>b) parent[a]=b;
    else parent[b]=a;

}
int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a == b) return 1;
    else return 0;
}

void solution(){
    int answer=0;
    int cnt=0;
    int parent[10001]={0};
    for(int i = 1; i<=V; i++)
        parent[i]=i;

    while(!pq.empty())
    {
        // 트리를 형성하는데 필요한 최소 간선의 개수는 (노드개수-1)개
        // 어차피 동일 부모를 탐색하는 부분에서 초과되는 cost값을 더하지 않지만
        // 조금이라도 시간을 줄이기 위해서 종료조건 걸어둠
        if(cnt==V-1)break;

        EDGE now = pq.top(); pq.pop();
        int from = now.from;
        int to = now.to;
        int cost = now.cost;
        
        // 동일 부모를 가지는 경우 
        if(findParent(parent,from,to)) continue;

        unionParent(parent,from,to);
        answer+=cost;
        cnt++;

    }

    cout<<answer;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}