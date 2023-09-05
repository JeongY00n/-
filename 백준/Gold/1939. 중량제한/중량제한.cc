#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

/*
    
    
*/

struct NODE{
    int to;
    int cost;
};

int N,M;
int is1, is2;
vector<NODE> v[100001];
int visited[100001];
int answer = 0, maxi=0;

bool cmp(NODE a, NODE b){
    return a.cost > b.cost;
}

void init(){
    cin>>N>>M;
    for(int i = 0; i<M; i++)
    {
        int from, to, cost;
        cin>>from>>to>>cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
        maxi = max(maxi, cost);
    }
    
    cin>>is1>>is2;

    for(int i = 1; i<=N; i++)
        sort(v[i].begin(), v[i].end(), cmp);
    
}

bool bfs(int num){
    queue<NODE> q;
    q.push({is1, (int)(2e9)});

    visited[is1]=1;

    while(!q.empty()){
        NODE now = q.front();
        q.pop();

        int from = now.to;
        int cost = now.cost;
        
        if(from == is2)
        {
            answer = max(answer, cost);
            return true;
        }

        for(int i = 0; i<v[from].size(); i++)
        {
            
            int to = v[from][i].to;
            if(v[from][i].cost < num)continue;
            if(visited[to]==1)continue;
            visited[to]=1;
            int mini = min(cost, v[from][i].cost);
            q.push({to, mini});
        }
    }
    
    return false;
}

void solution(){
    int left = 0, right = maxi;
    while(left<=right){
        int mid = (left+right)/2;
        memset(visited, 0 , sizeof(visited));
        if(bfs(mid))
            left = mid+1;
        
        else
            right = mid-1;

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