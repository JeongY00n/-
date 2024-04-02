#include<iostream>
#include<queue>
using namespace std;

/*
    우선순위 큐를 사용해서 먼저 푸는 것이 좋은 문제에 대한 문제 번호를 오름차순으로 정렬
*/
int N,M;
int cnt[32001];
priority_queue<int, vector<int>, greater<>> pq[32001];
priority_queue<int, vector<int>, greater<>> q;
void init(){
    cin>>N>>M;
    for(int i = 0; i<M; i++)
    {
        int n,m;
        cin>>n>>m;
        pq[n].push(m); // n문제 다음 m문제
        cnt[m]++; // m문제보다 먼저 풀어야하는 문제의 개수
    }
    for(int i = 1; i<=N; i++)
    {
        if(cnt[i]==0)
            q.push(i);
    }
}

void dfs(int idx){
    cout<<idx<<" ";
    q.pop();
    while(!pq[idx].empty()){
        cnt[pq[idx].top()]--;
        if(!cnt[pq[idx].top()])
            q.push(pq[idx].top());
        pq[idx].pop();
    }
    if(q.empty())return;
    dfs(q.top());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(q.top());

    return 0;
}