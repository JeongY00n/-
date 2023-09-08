#include<iostream>
#include<queue>
using namespace std;

/*
    다른 색이 나오는 경우는 queue에 넣지 않는다
*/

int n,m;
char map[50][50];
int visited[50][50];
int dir[5];
int fy[] = {0,-1,0,1,0};
int fx[] = {0,0,-1,0,1};
int cnt[26];
int circle;

void init(){
    cin>>n>>m;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>map[i][j];
            cnt[map[i][j]-'A']++;
        }
    }
}
void solution(int y, int x, int d){
    if(circle)return;

    visited[y][x]=1;
    for(int i = 1; i<=4; i++)
    {
        if(i%2 == d%2 && i!=d)continue;

        int ny = y + fy[i];
        int nx = x + fx[i];

        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        if(map[ny][nx]!=map[y][x])continue;
        if(visited[ny][nx]==1)
        {
            circle = 1;
            break;
        }

        solution(ny, nx, i);
    }
    visited[y][x]=0;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(cnt[map[i][j]-'A']<4)continue;
            solution(i,j,-1);
            
            if(circle)
            {
                cout<<"Yes";
                break;
            }
        }
        if(circle) break;
    }

    if(!circle)
        cout<<"No";

    return 0;
}