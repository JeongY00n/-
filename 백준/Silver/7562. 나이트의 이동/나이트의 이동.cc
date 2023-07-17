#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

/*
최단 경로
bfs
*/
struct Coord{
    int y, x, cnt;
};

int n, start_y, start_x, end_y, end_x, answer;
int map[300][300];
int visited[300][300];

void init(){
    cin>>n;
    cin>>start_y>>start_x;
    cin>>end_y>>end_x;
    memset(visited, 0, sizeof(visited));
}

void solution(){
    if(start_y==end_y && start_x==end_x)
    {
        answer = 0;
        return;
    }

    queue<Coord> q;
    q.push({start_y, start_x, 0});
    visited[start_y][start_x]=1;

    int fy[] = {2, 2,1,-1,-2,-2,  1,-1};
    int fx[] = {1,-1,2, 2, 1,-1, -2,-2};
    while (!q.empty())
    {
        Coord now = q.front();
        q.pop();

        for(int i = 0; i<8; i++)
        {
            int ny = now.y + fy[i];
            int nx = now.x + fx[i];

            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(visited[ny][nx]==1)continue;
            if(ny == end_y && nx == end_x)
            {
                answer = now.cnt+1;
                return;
            }
            visited[ny][nx]=1;
            q.push({ny, nx, now.cnt+1});
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case=0;
    cin>>test_case;
    for(int tc=0; tc<test_case; tc++)
    {
        init();
        solution();
        cout<<answer<<"\n";
    }
    return 0;
}