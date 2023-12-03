#include<iostream>
#include<queue>
#include<string.h>
using namespace std;


/*
    이다솜파 학생들로 4명 이상이 포함되게 조합을 만들어서  연결되어있는지 확인
*/

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
int make7[25];
char map[5][5];
int answer;

// 연결가능한 위치에 있는지 확인
void bfs(){
    queue<pair<int,int>> q;
    int cnt=1;
    int visited[25]={0};

    for(int i = 0; i<25; i++)
    {
        if(make7[i]==1)
        {
            visited[i]=1;
            q.push({i/5, i%5});
            break;
        }
    }

    while(!q.empty()){

        pair<int, int> now = q.front();
        q.pop();

        int y = now.first;
        int x = now.second;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];

            if(ny<0||nx<0||ny>=5||nx>=5)continue;
            if(make7[ny*5+nx]==0)continue;
            if(visited[ny*5+nx]==1)continue;
            visited[ny*5+nx]=1;

            cnt++;

            q.push({ny,nx});
        }
    }

    if(cnt==7) 
        answer++;

    
}

// 칠공주파에 포함할 이다솜파 4~5명 조합
void Combine(int idx, int cnt, int ycnt){
    if(cnt==7)
    {
        if(ycnt<=3) bfs();
        return;
    }

    for(int i=idx; i<25; i++)
    {
        make7[i]=1;
        if(map[i/5][i%5]=='Y')
            Combine(i+1, cnt+1, ycnt+1);
        else
            Combine(i+1, cnt+1, ycnt);
        make7[i]=0;
    }
}

void solution(){

    Combine(0,0,0);
    
    cout<<answer;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i<5; i++)
        for(int j = 0; j<5; j++)
            cin>>map[i][j];

    solution();

    return 0;
}