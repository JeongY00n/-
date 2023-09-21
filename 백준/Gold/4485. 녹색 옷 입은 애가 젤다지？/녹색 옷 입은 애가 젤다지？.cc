#include<iostream>
#include<queue>
using namespace std;


struct Coord{
    int y, x, sum;

    bool operator <(const Coord&other) const{
        return sum > other.sum;
    }
};
int n, map[125][125];
int visited[125][125];
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin>>map[i][j];
    fill(&visited[0][0],&visited[124][125],2e9);
}

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
/*void solution(int y, int x, int sum){
    if(sum>=answer)return;
    if(sum>visited[y][x])return;
    if(y==n-1 && x ==n-1)
    {
        answer = min(answer, sum);
        return;
    }

    for(int i = 0; i<4; i++)
    {
        int ny = y+fy[i];
        int nx = x+fx[i];

        if(ny<0||nx<0||ny>=n||nx>=n)continue;
        if(visited[ny][nx]<=sum+map[ny][nx])continue;
        int a = visited[ny][nx];
        visited[ny][nx]=sum+map[ny][nx];
        solution(ny, nx, visited[ny][nx]);
        visited[ny][nx]=a;
    }
}*/

void solution(){
    priority_queue<Coord> pq;
    pq.push({0,0,map[0][0]});
    visited[0][0]=map[0][0];

    while(!pq.empty()){
        Coord now = pq.top();
        pq.pop();

        int y = now.y;
        int x = now.x;
        int sum = now.sum;

        if(sum>visited[y][x])continue;

        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];

            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(visited[ny][nx]<=sum+map[ny][nx])continue;
            visited[ny][nx]=sum+map[ny][nx];
            pq.push({ny, nx, visited[ny][nx]});

        }
    } 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num=0;
    while(1){
        num++;
        init();
        if(n==0)break;
        solution();
        //solution(0,0,map[0][0]);
        cout<<"Problem "<<num<<": "<<visited[n-1][n-1]<<"\n";
    }

    return 0;
}