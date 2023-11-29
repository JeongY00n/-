#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
    각 칸에 대해 상하좌우로 인구수 비교
    만약 인구수 차이가 L명 이상 R명 이하라면 구경선을 연다
    국경선을 연 나라 번호를 저장
*/
int n, L, R; 
int map[50][50];
void init(){
    cin>>n>>L>>R;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin>>map[i][j];
}

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
int flag=1;
void solution(){
    int visited[50][50]={0};
    for(int i = 0; i<n*n; i++)
    {
        int sy = i/n;
        int sx = i%n;
        
        if(visited[sy][sx]==1)continue;

        queue<pair<int, int>> q;
        queue<pair<int, int>> border;
        q.push({sy,sx});
        border.push({sy,sx});
        visited[sy][sx]=1;
        int people = map[sy][sx];

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

                if(ny<0||nx<0||ny>=n||nx>=n)continue;
                if(visited[ny][nx]==1)continue;
                if(abs(map[y][x]-map[ny][nx])>=L && abs(map[y][x]-map[ny][nx])<=R)
                {
                    visited[ny][nx]=1;
                    q.push({ny,nx});
                    border.push({ny,nx});
                    people+=map[ny][nx];
                    flag=1;
                }   
            }
        }
        int size = border.size();
        people/=size;
        while(!border.empty()){
            pair<int, int> now=border.front();
            border.pop();
            map[now.first][now.second]=people;
        }
        
    }


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int time = 0;
    while(flag)
    {
        flag=0;
        time++;
        solution();
    }
    cout<<time-1;
    return 0;
}