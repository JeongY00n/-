#include<iostream>
#include<algorithm>
using namespace std;

/*
    * 경우 *
    - 부수는 경우
    - 부수지 않고 뚫린 길로 가는 경우
    (x,y)=>(n,m)
*/

int n,m;
char map[100][101];
int visited[100][100], answer = 2e9;
void init(){
    cin>>m>>n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m ;j++)
            cin>>map[i][j];

    fill(&visited[0][0], &visited[99][100], 2e9);
}


int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
void solution(int y, int x){
    if(y == n-1 && x == m-1)
    {
        answer = min(answer, visited[y][x]);
        return;
    }
    for(int i = 0; i<4; i++)
    {
        int ny = y+fy[i];
        int nx = x+fx[i];
        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        // 뚫려있는 경우
        if(map[ny][nx]=='0')
        {
            if(visited[ny][nx]<=visited[y][x])continue;
            visited[ny][nx]=visited[y][x];
            solution(ny, nx);
        }
        // 뚫어야하는 경우
        else if(map[ny][nx]=='1')
        {
            // 뚫음
            if(visited[ny][nx]<=visited[y][x]+1)continue;
            visited[ny][nx]=visited[y][x]+1;
            solution(ny, nx);
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    visited[0][0]=0;
    solution(0,0);
    cout<<answer;

    return 0;
}