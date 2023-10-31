#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;


/*
    연결된 노드끼리는 같은 그룹에 속할 수 없음
    초기화
*/

int V, E;
vector<int> e[20001];
int visited[20001], group[20001];

void init(){
    cin>>V>>E;

    for(int i = 1; i<=V; i++)
        e[i].clear();
        
    for(int i = 0; i<E; i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    // 방문체크 초기화
    memset(visited, 0, sizeof(visited));
    memset(group, 0, sizeof(group));
}


int solution(int n){
    queue<int> q;
    q.push(n);

    visited[n]=1;
    group[n]=1;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        int color;

        if(visited[now]==0)
            color = 1;  
        else
            color = group[now];

        for(int i = 0; i<e[now].size(); i++)
        {
            // 방문한 적이 있는데 인접한 정정과 같은 그룹에 속해있는 경우
            // 이분 그래프가 아니다
            if(visited[e[now][i]]!=0 && group[e[now][i]]==color)
                return 0;
            
            // 방문한 적이 없으면 그룹 설정
            if(visited[e[now][i]]==0)
            {
                if(color==1)    
                    group[e[now][i]]=2;
                else
                    group[e[now][i]]=1;
                
                visited[e[now][i]]=1;
                q.push(e[now][i]);
            }
        }
        
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;

    for(int tc=1; tc<=T; tc++)
    {
        init();
        int flag=0;
        // 모든 정점이 연결되어있지 않을 수 있으므로 정점 하나하나 확인해봐야함
        for(int i = 1; i<=V; i++)
        {
            if(visited[i]==1)continue;
            flag = solution(i);
            if(!flag) 
            {
                cout<<"NO\n";
                break;
            }
        }
        if(flag)
            cout<<"YES\n";
    }

    return 0;
}