#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

/*
    지도에서 1인 경우 +1하지 않고
    0인 경우 +1
*/

struct Coord{
    int y, x, cost;

    bool operator<(const Coord&other)const{
        if(cost < other.cost) return false;
        if(cost > other.cost) return true;

        return false;
    }
};

int N, map[100][100],answer=2e9;
int visited[100][100];
void init(){
    cin>>N;

    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin>>map[i][j];
}

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
void makenum(int y, int x, int num){
    queue<pair<int,int>> qq;
    qq.push({y,x});
    map[y][x]=num;
    visited[y][x]=1;

    while(!qq.empty()){
        pair<int,int> now = qq.front();
        qq.pop();
        
        for(int i = 0; i<4; i++)
        {
            int ny = now.first+fy[i];
            int nx = now.second+fx[i];

            if(ny<0||nx<0||ny>=N||nx>=N)continue;
            if(visited[ny][nx]==1)continue;
            if(map[ny][nx]==1){
                map[ny][nx]=num;
                qq.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }
}

void bfs(int num){
    priority_queue<Coord> q;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
        {
            if(map[i][j]==num)
                q.push({i,j,0});
        }

    while(!q.empty()){
        Coord now = q.top();
        q.pop();

        int y = now.y;
        int x = now.x;
        int cost = now.cost;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];
        
            if(ny<0||nx<0||ny>=N||nx>=N)continue;

            if(map[ny][nx]!=num && map[ny][nx]!=0)
            {
                answer = min(answer,cost);
                return;
            }

            if(map[ny][nx]!=0)continue;
            if(visited[ny][nx]==1)continue;
            visited[ny][nx]=1;
            q.push({ny,nx,cost+1}); 
        } 
    }
}

void solution(){
    int num=1;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(map[i][j]!=1 || map[i][j]==0)continue;
            num++;
            memset(visited,0,sizeof(visited));
            makenum(i,j,num);
            bfs(num);
        }
    }

    // for(int i = 0; i<N; i++)
    // {
    //     cout<<"\n";
    //     for(int j = 0; j<N; j++)
    //         cout<<map[i][j]<<" ";
    // }

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    cout<<answer;

    return 0;
}