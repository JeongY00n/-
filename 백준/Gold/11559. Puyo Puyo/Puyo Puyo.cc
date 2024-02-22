#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

/*
    bfs를 통해 주변에 같은 색상의 뿌요들이 몇 개 있는지 확인하고
    동일한 색상이 4개 이상이면 터트린다.
    각각의 뿌요들에 대해 처리를 해주고
    현재 상태에서 터트릴 수 있는 뿌요들을 모두 터트린 다음에 
    중력 적용해준다.

*/

char map[12][6];
int visited[12][6]={0};
queue<pair<int, int>> puyo;
void init(){
    for(int i = 0; i<12; i++)
    {
        for(int j = 0; j<6; j++)
        {
            cin>>map[i][j];
            if(map[i][j]!='.')
                puyo.push({i,j});
            
            
        }
    }
}

queue<pair<int, int>> boom;
int nextflag=1;
void gravity(){
    nextflag=0;
    
    while(!boom.empty())
    {
        
        pair<int, int> now = boom.front();
        boom.pop();

        int y = now.first;
        int x = now.second;
        
        
        map[y][x]='.';
        nextflag=1;
    }

    memset(visited,0,sizeof(visited));
    for(int i = 11; i>=0; i--)
    {
        for(int j = 0; j<6; j++)
        {
            if(map[i][j]!='.')
            {

                int k = i;
                while(1)
                {
                    k++;
                    if(k==12 || map[k][j]!='.')
                    {
                        puyo.push({k-1,j});
                        break;
                    }

                    char a = map[k-1][j];
                    map[k-1][j] = map[k][j];
                    map[k][j] = a;
                }
            }
        }
    }
    // cout<<"\n";
    // for(int i = 0; i<12; i++)
    // {
    //     for(int j = 0; j<6; j++)
    //         cout<<map[i][j];
    //     cout<<"\n";
    // }
}

void bfs(pair<int, int> yx){

    int fy[]={-1,1,0,0};
    int fx[]={0,0,-1,1};

    queue<pair<int, int>> q;
    q.push(yx);
    char color = map[yx.first][yx.second];
    
    queue<pair<int, int>> isboom;
    isboom.push({yx.first, yx.second});

    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        int y = now.first;
        int x = now.second;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];

                
            if(ny<0||nx<0||ny>=12||nx>=6)continue;
            if(map[ny][nx]==color && visited[ny][nx]==0)
            {
                q.push({ny,nx});
                isboom.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }

    if(isboom.size()>=4)
    {
        while(!isboom.empty())
        {
            boom.push(isboom.front());
            isboom.pop();
        }
    }
}
  int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int time=0;
    while(nextflag)
    {
        while(!puyo.empty())
        {
            pair<int, int> now = puyo.front();
            puyo.pop();
            
            int y = now.first; int x = now.second;
            if(visited[y][x]==1)continue;

            visited[y][x]=1;
            bfs(now);
        }

        gravity();
        if(nextflag)
            time++;
    }

    cout<<time;

    return 0;
}