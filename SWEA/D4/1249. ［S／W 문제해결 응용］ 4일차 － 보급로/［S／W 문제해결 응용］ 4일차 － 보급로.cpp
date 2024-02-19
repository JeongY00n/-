#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
    시간이 최소로 걸리는 경로
    다익스트라
*/
struct Coord{
    int y, x, cost;

    // 오름차순
    bool operator<(const Coord&other)const{
        return cost>other.cost;
    }
};

int N;
char map[100][100];
void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin>>map[i][j];
}

void dijkstra(int tc){
    int answer = 0;
    priority_queue<Coord> pq;
    pq.push({0,0,0});

    int visited[100][100];
    fill(&visited[0][0], &visited[99][100], 2e9);
    visited[0][0]=0;

    int fy[]={-1,1,0,0};
    int fx[]={0,0,-1,1};

    while(!pq.empty()){
        Coord now = pq.top();
        pq.pop();

        int y = now.y;
        int x = now.x;
        int cost = now.cost;

        for(int i = 0; i<4; i++)
        {   
            int ny = y+fy[i];
            int nx = x+fx[i];

            if(ny<0||nx<0||ny>=N||nx>=N)continue;
            if(visited[ny][nx]<=cost+map[ny][nx]-'0')continue;
            visited[ny][nx]=cost+map[ny][nx]-'0';
            // 목적지 도착한 경우
            if(ny==N-1&&nx==N-1)
            {
                answer = visited[ny][nx];
                cout<<"#"<<tc<<" "<<answer<<"\n";
                return;
            }
            pq.push({ny,nx,visited[ny][nx]});
        }

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;

    for(int tc=1; tc<=T; tc++)
    {
        init();
        dijkstra(tc);
    }

    
    return 0;
}