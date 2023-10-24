#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

struct INFO{
    int y, x, size, time;

    bool operator<(const INFO&other)const{

        if(time<other.time) return false;
        if(time>other.time) return true;

        if(y<other.y) return false;
        if(y>other.y) return true;

        if(x<other.x) return false;
        if(x>other.x) return true;

        return false;
    }
};
int n, map[20][20];
int fish;
INFO shark;
int cnt;
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>map[i][j];
            if(map[i][j]>=1 && map[i][j]<=6)
                fish++;
            if(map[i][j]==9)
            {
                map[i][j]=0;
                shark = {i,j,2,0};
            }
        }
    }
}

int fy[]={-1,0,0,1};
int fx[]={0,-1,1,0};

void bfs(){
    priority_queue<INFO> q;
    priority_queue<INFO> pq;
    q.push(shark);

    int visited[20][20]={0};
    visited[shark.y][shark.x]=1;

    while(!q.empty()){
        INFO now = q.top();
        q.pop();

        int y = now.y;
        int x = now.x;
        int size = now.size;

        // 물고기를 먹은 경우
        // 먹은 물고기 갯수에 +1
        // 살아있는 물고기 갯수에 -1
        // 만약 먹을 물고기 갯수가 아기상어의 크기와 같다면 size에 +1
        // 물고기 위치의 값 0으로 갱신
        // 상어의 정보 갱신
        if(!pq.empty())
        {
            if(pq.top().time <= now.time) {
                cnt++;
                fish--;

                if(cnt==size)
                {
                    size++;
                    cnt=0;
                }

                int ny = pq.top().y;
                int nx = pq.top().x;
                int time = pq.top().time;

                map[ny][nx]=0;
                shark = {ny, nx, size, time};
                memset(visited, 0, sizeof(visited));
                visited[shark.y][shark.x]=1;

                y = ny; x = nx; 

                while(!q.empty())
                    q.pop();
                
                while(!pq.empty())
                    pq.pop();
            
            }
        }

        if(fish==0) break;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];
            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(map[ny][nx]>size) continue;
            if(visited[ny][nx]==1)continue;
            visited[ny][nx]=1;

            if(map[ny][nx] < size && map[ny][nx]!=0)
                pq.push({ny,nx,size,now.time+1});
            

            q.push({ny,nx,size, now.time+1});
        }

        
    }

    cout<<shark.time;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    bfs();

    return 0;
}