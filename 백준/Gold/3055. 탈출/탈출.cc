#include<iostream>
#include<queue>

using namespace std;

/*
 * 물이 찰 예정인 칸에는 이동할 수 없음
 * 매 분마다 고슴도치는 인접한 네 칸 중 하나로 이동 가능
 * 매 분마다 물과 인접해 있는 칸은 물이 찬다
 * 물과 고슴도치는 돌을 통과할 수 없음
 * 물은 비버의 소굴로 이동할 수 없음
 * 
 * 
 * 물 먼저 확장
 * 그 이후에 고슴도치 이동
*/

int R,C;
char map[50][50];
queue<pair<int, int>> water, s;
pair<int, int> d;
void init(){
    cin>>R>>C;
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='S') s.push({i,j});
            if(map[i][j]=='D') d={i,j};
            if(map[i][j]=='*') 
                water.push({i,j});
        }
}
int dy[]={-1,1,0,0}, dx[]={0,0,-1,1};
void water_move(){
    int size=water.size();
    for(int i = 0; i<size; i++)
    {
        pair<int, int> now = water.front(); water.pop();
        for(int j = 0; j<4; j++)
        {
            int ny = now.first+dy[j];
            int nx = now.second+dx[j];
            //cout<<ny<<","<<nx<<"\n";
            if(ny<0||nx<0||ny>=R||nx>=C)continue;
            if(map[ny][nx]=='.'||map[ny][nx]=='S')
            {
                map[ny][nx]='*';
                water.push({ny,nx});
            }

        }
    }
}
void print(){
    for(int i=0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
            cout<<map[i][j];
        cout<<"\n";
    }
}
int visited[50][50],end_flag=0;
void bfs(int time){
    queue<pair<int, int>> nq;
    
    while(!s.empty()){
        pair<int, int> now = s.front(); s.pop();
        if(visited[now.first][now.second])continue;
        visited[now.first][now.second]=1;

        for(int i = 0; i<4; i++)
        {
            int ny = now.first+dy[i];
            int nx = now.second+dx[i];
            if(ny<0||nx<0||ny>=R||nx>=C)continue;
            //cout<<ny<<","<<nx<<"\n";
            if(visited[ny][nx]||!(map[ny][nx]=='D'||map[ny][nx]=='.'))continue;

            // 목적지 도착
            if(ny==d.first&&nx==d.second)
            {
                end_flag=1;
                cout<<time;
                return;
            }
               
            // map[ny][nx]='S'; 
            nq.push({ny,nx});

            // print();
            // cout<<"\n";
        }
    }

    s=nq;
}

void solution(){

    int time=0;
    while(1){
        time++;
        water_move();
        bfs(time);

        if(end_flag)
            return;
        if(s.empty())
        {
            cout<<"KAKTUS";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}