#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

struct Node{
    int f1, cnt;
};
// bfs로 연결된 5명의 친구들 탐색되면 끝
int n, m, answer;
vector<Node> f[2000];
int visited[2000];
void init(){
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int f1 = 0, f2 = 0;
        cin>>f1>>f2;
        f[f1].push_back({f2, 0});
        f[f2].push_back({f1, 0});
    }
}
void dfs(int cnt, int idx){
    if(cnt == 5)
    //cout<<cnt<<" ";
    {
        answer = 1;
        return;
    }
    for(int i = 0; i<f[idx].size(); i++)
    {
        int ff = f[idx][i].f1;
        if(visited[ff]==1)continue;
        visited[ff]=1;
        dfs(cnt+1, ff);
        visited[ff]=0;
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        memset(visited,0,sizeof(visited));
        answer = 0;
        visited[i]=1;
        dfs(1,i);
        if(answer==1)
        {
            flag = 1;
            cout<<1;
            break;
        }
    }
    //cout<<"\n";
    if(!flag)
        cout<<0;
    return 0;
}