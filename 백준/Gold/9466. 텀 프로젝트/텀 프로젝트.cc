#include<iostream>
#include<string.h>
using namespace std;

/*
    4-7-6-4

    1-3
    2-1-3
    5-3
    연결되어있어야함

    어느팀에도 속하지 않는 학생들의 수
    학생 번호마다 돌아가면서 본인 번호로 돌아오는지 확인
    이 과정에 포함된 번호들은 다시 돌지 않음
    dfs로 그룹된 경우는 표시를 해줌

*/
int n, st[100001];
int check[100001];
int visited[100001];
void init(){
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        cin>>st[i];
    }
    memset(check, 0, sizeof(check));
    memset(visited, 0, sizeof(visited));
}
int flag=0;
void dfs(int id, int now){
    if(id == now){ // 시작 번호로 돌아온 경우
        check[id]=1;
        return;
    }

    if(visited[now]==1){ // 시작 번호로 돌아가지 못하고 다른 번호에 재방문
        flag=1;
        check[now]=1;
        check[id]=-1;
        visited[now]=0;
        return;
    }

    if(check[now]==1 || check[now]==-1) // 이미 앞에서 해당 학생의 팀 구성 여부가 결정된 경우
        return;
    

    visited[now]=1;
    dfs(id, st[now]);

    if(visited[now]==0)
    {
        flag=0;
        return;
    }

    visited[now]=0;

    if(check[id]==1||flag==1)
        check[now]=1;
    else
        check[now]=-1;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    for(int tc=0; tc<T; tc++)
    {
        init();
        int cnt=0;
        for(int i = 1; i<=n; i++)
        {
            if(check[i]==1||check[i]==-1)continue;
            dfs(i,st[i]);
        }

        for(int i = 1; i<=n; i++)
            if(check[i]!=1) cnt++;            
        
        cout<<cnt<<"\n";
    }

    return 0;
}