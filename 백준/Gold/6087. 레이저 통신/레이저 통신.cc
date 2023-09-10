#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
    좌표와 방향에 대한 인덱스를 가진 배열에 이동하면서 사용된 거울의 갯수 저장
    dijkstra  
*/

struct Coord{
    int y, x, dir, cnt;
};

struct cmp{
    bool operator()(Coord a, Coord b){
        return a.cnt > b.cnt;
    }
};

int h,w;
vector<pair<int, int>> CC;
char map[100][100];
// 상하좌우(0,1,2,3)
int fy[] = {-1,1,0,0}; 
int fx[] = {0,0,-1,1};
int answer = 2e9;
int check[100][100][4];

void init(){
    cin>>w>>h;
    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<w; j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='C')
                CC.push_back({i,j});
        }
    }    
    fill(&check[0][0][0], &check[99][99][3], 2e9);
}

void solution(){
    priority_queue<Coord, vector<Coord>, cmp> pq;

    for(int i=0; i<4; i++){
        int ny = CC[0].first + fy[i];
        int nx = CC[0].second + fx[i];
        
        if(ny<0||nx<0||ny>=h||nx>=w)continue;
        if(map[ny][nx]=='*')continue;
        
        pq.push({ny, nx, i, 0});
        check[CC[0].first][CC[0].second][i]=0;
    }


    while(!pq.empty()){
        Coord now = pq.top();
        pq.pop();

        int y = now.y;
        int x = now.x;
        int dir = now.dir;
        int cnt = now.cnt;

        if(y==CC[1].first && x==CC[1].second)
        {
            answer = cnt;
            return;
        }
        
        
        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];

            if(ny<0||nx<0||ny>=h||nx>=w)continue;
            if(map[ny][nx]=='*')continue;
            

            if(dir == 0 || dir == 1)
            {
                if(i == 2 || i == 3)
                {
                    if(check[ny][nx][i] > cnt+1)
                    {
                        check[ny][nx][i]=cnt+1;
                        pq.push({ny, nx, i, check[ny][nx][i]});
                    }
                    
                }
                else if(dir == i)
                {
                    if(check[ny][nx][i] > cnt)
                    {
                        check[ny][nx][i]=cnt;
                        pq.push({ny, nx, i, check[ny][nx][i]});
                    }
                }
            }
            else if(dir == 2 ||  dir == 3)
            {
                if(i == 0 || i == 1)
                {
                    if(check[ny][nx][i] > cnt+1)
                    {
                        check[ny][nx][i]=cnt+1;
                        pq.push({ny, nx, i, check[ny][nx][i]});
                    }
                }
                else if(dir == i)
                {
                    if(check[ny][nx][i] > cnt)
                    {
                        check[ny][nx][i]=cnt;
                        pq.push({ny, nx, i, check[ny][nx][i]});
                    }
                }
            }

        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    cout<<answer;
    return 0;
}
