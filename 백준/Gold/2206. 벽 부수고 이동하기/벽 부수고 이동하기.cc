#include<iostream>
#include<queue>
using namespace std;

/*
    다익스트라
    벽을 부순지에 대한 여부와 이동한 칸의 수를 저장

*/

struct Coord{
    int y,x,cost,temp; // 현재좌표, 이동한 칸의 수, 벽을 부쉈는지

    bool operator<(const Coord&other)const{
        return cost>other.cost;
    }
};
int N,M;
char map[1000][1000];
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin>>map[i][j];
}
void dijkstra(){
    priority_queue<Coord> pq;
    pq.push({0,0,1,0});

    int visited[2][1000][1000]={0}; //부순벽의 갯수, 좌표y,x
    visited[0][0][0]=1; 

    int dy[]={-1,1,0,0};
    int dx[]={0,0,-1,1};
    while(!pq.empty()){
        Coord now = pq.top();
        pq.pop();

        int y = now.y;
        int x = now.x;
        int cost = now.cost;
        int temp = now.temp;

        // 목적지 도착!
        if(y==N-1&&x==M-1)
        {
            cout<<cost;
            return;
        }
        for(int i = 0; i<4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny<0||nx<0||ny>=N||nx>=M)continue;
            if(visited[temp][ny][nx]==1)continue;
            if(map[ny][nx]=='1')
            {
                if(temp==0)
                pq.push({ny,nx,cost+1,1});
                visited[1][ny][nx]=1;
                continue;
            }
            visited[temp][ny][nx]=1;
            
            // // 목적지 도착!
            // if(ny==N-1&&nx==M-1)
            // {
            //     cout<<cost+1;
            //     return;
            // }

            pq.push({ny,nx,cost+1,temp});

        }
    }

    cout<<-1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    dijkstra();

    return 0;
}