#include<iostream>

using namespace std;

int n,m,answer;
int map[500][500];
void init(){
    cin>>n>>m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>map[i][j];
}

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
int visited[500][500];
void solution(int y, int x, int cnt, int sum){
    if(cnt==4)
    {
        answer = max(answer, sum);
        return;
    }
    for(int i = 0; i<4; i++)
    {
        int ny = y + fy[i];
        int nx = x + fx[i];

        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        if(visited[ny][nx]==1)continue;
        
        visited[ny][nx]=1;
        solution(ny, nx, cnt+1, sum+map[ny][nx]);
        visited[ny][nx]=0;
    }
}

void tetromino(int y, int x){
    int sum1 = 0, sum2 = 0, result=0;
    // 상하
    for(int i = 0; i<2; i++)
    {
        int ny = y + fy[i];

        if(ny<0||ny>=n)
        {
            sum1=0;
            break;
        }
        sum1+=map[ny][x];
    }
    if(sum1!=0)
    {   
        sum1+=map[y][x];
        for(int i = 2; i<4; i++)
        {
            int nx = x + fx[i];

            if(nx<0||nx>=m) continue;
            result = max(result,sum1+map[y][nx]);
        }
    }
    // 좌우
    for(int i = 2; i<4; i++)
    {
        int nx = x + fx[i];

        if(nx<0||nx>=m)
        {
            sum2=0;
            break;
        }
        sum2+=map[y][nx];
    }
    if(sum2!=0)
    {
        sum2+=map[y][x];
        for(int i = 0; i<2; i++)
        {
            int ny = y + fy[i];

            if(ny<0||ny>=n) continue;
            result = max(result,sum2+map[ny][x]);
        }
    }
    answer = max(answer, result);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    
    for(int y = 0; y<n; y++)
    {
        for(int x = 0; x<m; x++)
        {

            visited[y][x]=1;
            solution(y,x,1,map[y][x]);
            visited[y][x]=0;
            tetromino(y,x);
        }
    }
    cout<<answer;
    return 0;
}