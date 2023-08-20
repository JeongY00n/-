#include<iostream>
#include<queue>
/*
    dp로 최소 이동 확인
    말처럼 움직인 횟수 저장
    이동하기 전에 해당 위치가 방문 가능한 위치인지 확인
*/
using namespace std;

struct Coord{
    int y,x,cnt,cost;
};
int k,w,h;
int map[200][200];
void init(){
    cin>>k>>w>>h;
    for(int i = 0; i<h; i++)
        for(int j = 0; j<w; j++)
            cin>>map[i][j];
}

int fy[] = {-1,1,0,0};
int fx[] = {0,0,-1,1};
int hy[] = {-2,-1,1,2,2,1,-1,-2};
int hx[] = {-1,-2,-2,-1,1,2,2,1};
int answer=2e9;


void solution(){
    queue<Coord> q;
    q.push({0,0,0,0});

    // 말처럼 움직인 횟수에 따라서 이동이 가능한 위치인지 파악
    // 같은 위치에 방문을 했을 때, 말처럼 움직여서 방문한 경우와 인접한 방향으로 움직여서 방문한 경우는 다름
    // 말처럼 움직인 순서는 무관
    int visited[200][200][31]={0};
    visited[0][0][0]=1;
    
    while(!q.empty()){
        Coord now = q.front();
        q.pop();

        int y = now.y;
        int x = now.x;
        int cnt = now.cnt;
        int cost = now.cost;
        
        if(y == h-1 && x == w-1)
        {
            answer = cost;
            return;
        }
        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];

            if(ny<0||nx<0||ny>=h||nx>=w)continue;
            if(map[ny][nx]==1)continue;
            if(visited[ny][nx][cnt]==1)continue;
            visited[ny][nx][cnt]=1;

            q.push({ny,nx,cnt,cost+1});
        }
        if(cnt==k)continue;
        for(int i = 0; i<8; i++)
        {
            int ny = y+hy[i];
            int nx = x+hx[i];

            if(ny<0||nx<0||ny>=h||nx>=w)continue;
            if(map[ny][nx]==1)continue;
            if(visited[ny][nx][cnt+1]==1)continue;

            visited[ny][nx][cnt+1]=1;
            q.push({ny,nx,cnt+1,cost+1});
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    if(answer==2e9)cout<<-1;
    else cout<<answer;

    return 0;
}