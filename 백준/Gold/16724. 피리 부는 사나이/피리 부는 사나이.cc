#include<iostream>

using namespace std;

int n,m;
char map[1001][1001];
int visited[1001][1001];
int safe_zone;
int answer = 2e9;
void init(){
    cin>>n>>m;
    for(int y = 1; y<=n; y++)
        for(int x = 1; x<=m; x++)
            cin>>map[y][x];

}
int cnt = 0;
void solution(int y, int x){

    // 1. map을 벗어난경우
    // 2. 시작점으로 돌아온 경우
    // 3. 도착 경로가 여러개인 경우
    
    if(visited[y][x]==-1) return;
    if(map[y][x]=='D')
    {
        if(visited[y+1][x] == cnt)
        {
            visited[y+1][x]=-1;
            safe_zone++;
            return;
        }
        else if(visited[y+1][x]>0)
            return;
        visited[y+1][x]=cnt;
        solution(y+1,x);
    }
    else if(map[y][x]=='U')
    {
        
        if(visited[y-1][x] == cnt)
        {
            visited[y-1][x]=-1;
            safe_zone++;
            return;
        }
        else if(visited[y-1][x]>0)
            return;
        visited[y-1][x]=cnt;
        solution(y-1,x);
    }
    else if(map[y][x]=='R')
    {
        
        if(visited[y][x+1] == cnt)
        {
            visited[y][x+1]=-1;
            safe_zone++;
            return;
        }
        else if(visited[y][x+1]>0)
            return;
        visited[y][x+1]=cnt;
        solution(y,x+1);
    }
    else if(map[y][x]=='L')
    {
        
        if(visited[y][x-1] == cnt)
        {
            visited[y][x-1]=-1;
            safe_zone++;
            return;
        }
        else if(visited[y][x-1]>0)
            return;
        visited[y][x-1]=cnt;
        solution(y,x-1);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    visited[1][1]=1;
    for(int y = 1; y<=n; y++)
    {
        for(int x = 1; x<=m; x++)
        {
            cnt++;
            solution(y,x);
        }
    }

    cout<<safe_zone;
    return 0;
}