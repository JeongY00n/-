#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


/*
    미친 아두이노는 벡터에 넣어둔다
    입력받은 방향대로 움직이면서 미친 아두이노를 한 칸씩 이동시킨다
    - 8가지 방향대로 움직였을 때의 좌표와 종수 아두이노 좌표의 거리를 계산했을 때 가까운 좌표로 이동

    입력받은 이동이 끝나면 바로 출력
    아두이노들의 충돌이 일어나면 제거
    - 하나씩 이동시키고 겹치는 좌표가 발생하면 해당 아두이노는 죽었음을 표시 -1로
*/


struct Coord{
    int y, x, on;
};
int R,C;
char map[100][100], dir[101];
vector<Coord> v;
pair<int, int> start;

void init(){
    cin>>R>>C;
    for(int y = 0; y<R; y++)
    {
        for(int x = 0; x<C; x++)
        {
            cin>>map[y][x];
            if(map[y][x]=='R')
                v.push_back({y,x,1});
            else if(map[y][x]=='I')
                start = {y,x};
        }
    }
    cin>>dir;
}
int dy[] = {0, 1,1,1,0,0,0,-1,-1,-1};
int dx[] = {0, -1,0,1,-1,0,1,-1,0,1};


int crazyArduino(){
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i].on == 0)continue;
        int y = v[i].y;
        int x = v[i].x;
        map[y][x]='.';

        // 종수의 아두이노와 가장 가까운 위치로 가는 좌표 찾기
        pair<int, int> mindist;
        int mini = 2e9;
        for(int j = 1; j<=9; j++)
        {
            int ny = y+dy[j];
            int nx = x+dx[j];

            if(ny<0||nx<0||ny>=R||nx>=C)continue;

            if(mini>(abs(ny-start.first)+abs(nx-start.second)))
            {
                mini = (abs(ny-start.first)+abs(nx-start.second));
                mindist = {ny,nx};
            }
        }

        v[i].y = mindist.first;
        v[i].x = mindist.second;
    }

    int check[100][100];
    vector<int> boom;
    // 앞에서 구한 좌표 map에 저장
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i].on == 0)continue;
        int y = v[i].y;
        int x = v[i].x;

        // 종수의 아두이노와 같은 칸으로 이동
        if(map[y][x]=='I')
            return 0;

        // 미친 아두이노들 충돌
        if(map[y][x]=='R')
        {
            boom.push_back({check[y][x]});
            boom.push_back({i});
        }
        
        check[y][x]=i;
        map[y][x]='R';
    }
    // 폭발
    for(int i = 0; i<boom.size(); i++)
    {
        v[boom[i]].on = 0;
        map[v[boom[i]].y][v[boom[i]].x]='.';
    }

    return 1;
}

int solution(){
    for(int i = 0; i<strlen(dir); i++)
    {
        int idx = (int)(dir[i]-'0');
        map[start.first][start.second]='.';
        start.first = start.first+dy[idx];
        start.second = start.second+dx[idx];

        // 중간에 미친 아두이노를 만나서 중단하게되는 경우
        if(map[start.first][start.second]=='R')
            return i;
        map[start.first][start.second]='I';
        
        int result = crazyArduino(); // 0은 중간 중단
        if(!result)
            return i;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int result = solution();

    if(result == -1)
    {
        for(int y = 0; y<R; y++)
        {
            for(int x = 0; x<C; x++)
                cout<<map[y][x];
            cout<<"\n";
        }
    }
    else
        cout<<"kraj "<<result+1;

    return 0;
}