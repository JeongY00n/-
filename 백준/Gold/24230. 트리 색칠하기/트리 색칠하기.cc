#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, color[200001];
vector<int> node[200001];
void init(){
    cin>>n;
    for(int i = 1; i<=n; i++)
        cin>>color[i];
    
    for(int i = 0; i<n-1; i++)
    {
        int a,b; cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
}

int answer, end_flag=0;
int visited[200001];
void coloring(int now, int c, int ncnt){
//    cout<<now<<" "<<answer<<"\n";
    if(ncnt==n)
    {
        return;
    }

    for(int i = 0; i<node[now].size(); i++)
    {
        int next = node[now][i];

        if(visited[next])continue;
        visited[next]=1;

        if(color[next]!=c)
            answer++;

        coloring(next, color[next], ncnt+1);
    }
}

void solution(){
    // 루트노드의 색상이 흰색이 아닌 경우
    if(color[1]!=0)
        answer++;
    visited[1]=1;
    coloring(1, color[1], 0);
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}