#include<iostream>
#include<queue>
using namespace std;

int R,C,T;
int map[50][50];
int answer;
pair<int, int> air;
queue<pair<int, int>> dirty;

void init(){
    cin>>R>>C>>T;
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            cin>>map[i][j];
            if(map[i][j]==-1 && map[i-1][j]!=-1)
                air = {i,i+1};
            if(map[i][j]>0)
                dirty.push({i,j});
        }
    }
}

void aircycle(int cmap[][50]){
    int firsty=air.first;
    int secondy=air.second;
    

    // 위
    for(int i = firsty; i>0; i--)
    {
        cmap[i][0]=cmap[i-1][0];
    }
    for(int j = 0; j<C-1; j++)
    {
        cmap[0][j] = cmap[0][j+1];
    }
    for(int i = 0; i<firsty; i++)
    {
        cmap[i][C-1]=cmap[i+1][C-1];
    }
    cmap[firsty][0]=0;
    for(int j = C-1; j>0; j--)
    {
        cmap[firsty][j] = cmap[firsty][j-1];
    }

    // 아래
    for(int i = secondy; i<R-1; i++)
    {
        cmap[i][0]=cmap[i+1][0];
    }
    for(int j = 0; j<C-1; j++)
    {
        cmap[R-1][j] = cmap[R-1][j+1];
    }
    for(int i = R-1; i>secondy; i--)
    {
        cmap[i][C-1]=cmap[i-1][C-1];
    }
    cmap[secondy][0]=0;
    for(int j = C-1; j>0; j--)
    {
        cmap[secondy][j] = cmap[secondy][j-1];
    }
    
}

void copymap(int cmap[][50]){
    answer=0;

    aircycle(cmap);

    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            map[i][j]=cmap[i][j];
            if(cmap[i][j]>0)
            {  
                answer+=cmap[i][j];
                dirty.push({i,j});
            }
        }
    }

    map[air.first][0]=-1;
    map[air.second][0]=-1;
    
    
}

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
void solution(){
    int cmap[50][50]={0};
    while(!dirty.empty())
    {
        pair<int, int> now = dirty.front();
        dirty.pop();

        int y = now.first;
        int x = now.second;
        int cost = map[y][x];

        for(int i = 0; i<4; i++)
        {
            int ny=y+fy[i];
            int nx=x+fx[i];

            if(ny<0||nx<0||ny>=R||nx>=C)continue;
            if(map[ny][nx]==-1)continue;

            cmap[ny][nx]+=(map[y][x]/5);
            cost-=(map[y][x]/5);
        }
        if(cost<0)
            cost=0;
        cmap[y][x]+=cost;
    }
    
    copymap(cmap);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    for(int i = 0; i<T; i++)
        solution();

    cout<<answer;

    
    return 0;
}