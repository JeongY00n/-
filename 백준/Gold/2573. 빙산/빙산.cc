#include<iostream>
#include<queue>

using namespace std;

/*
    빙산의 각 부분에 대해 큐에 넣어준다.
    한 덩어리임을 어떻게
*/
struct INFO{
    int y,x,time;
};
int n,m;
int map[300][300];
int copymap[300][300]={0};
queue<INFO> q;
void init(){
    cin>>n>>m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>copymap[i][j];
}

int endflag=0;
int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
void bfs(){

    while(!q.empty()){
        INFO now = q.front();
        q.pop();

        int y = now.y;
        int x = now.x;
        int time = now.time;
        int water=0;

        // 이미 바다의 일부가 된 경우
        if(map[y][x]==0)continue;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];
            
            if(ny<0||nx<0||ny>=n||nx>=m)continue;
            if(map[ny][nx]==0) // 바닷물과 접하는 면의 갯수
                water++;
        }
        // 0이하인 경우 0으로 저장
        if(map[y][x]-water<=0) copymap[y][x]=0;
        else copymap[y][x] = map[y][x]-water;
        
    }    
}

bool findland(int y, int x){
   
    queue<INFO> qq;
    qq.push({y,x});
    int visited[300][300]={0};
    visited[y][x]=1;
    int cnt=0;

    while(!qq.empty()){
        INFO now = qq.front();
        qq.pop();

        y = now.y;
        x = now.x;
        cnt++;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];
            
            if(ny<0||nx<0||ny>=n||nx>=m)continue;
            if(visited[ny][nx]==1)continue;
            if(map[ny][nx]==0)continue;

            visited[ny][nx]=1;
            qq.push({ny,nx});
        }
    }
    if(cnt<q.size()) return 1;
    else return 0;
}

void solution(){
    int time=-1;
    while(1)
    {
        time++;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                map[i][j]=copymap[i][j];
                if(copymap[i][j]!=0)
                    q.push({i,j,time});
            }
        }

        if(findland(q.front().y, q.front().x))
        {
            cout<<time;
            break;
        }

        if(q.empty())
        {
            cout<<0;
            break;
        }

        bfs();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}