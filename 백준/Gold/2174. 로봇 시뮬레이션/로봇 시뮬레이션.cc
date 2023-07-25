#include<iostream>
#include<algorithm>
using namespace std;

/*
L: 로봇이 향하고 있는 방향을 기준으로 왼쪽으로 90도 회전한다.
R: 로봇이 향하고 있는 방향을 기준으로 오른쪽으로 90도 회전한다.
F: 로봇이 향하고 있는 방향을 기준으로 앞으로 한 칸 움직인다.
로봇에 idx, 위치, 방향에 대한 정보가 저장되어야함 => 구조체
*/

struct ROBOT{
    int x,y,go;
};

int n,m;
int map[101][101];
int robot_n, op_n;
ROBOT robot[101];

void init(){
    cin>>n>>m;
    cin>>robot_n>>op_n;
    for(int i = 1; i<=robot_n; i++)
    {
        int y=0,x=0,go=0;
        char dir;
        cin>>x>>y>>dir;

        if(dir=='N')
            go=0;
        else if(dir=='W')
            go=1;
        else if(dir=='S')
            go=2;
        else if(dir=='E')
            go=3;

        y = abs((m+1)-y);
        robot[i]={x,y,go};
        map[y][x]=i;
    }
}

bool isOK(int y, int x, int idx){
    if(y<1||x<1||y>m||x>n)
    {
        cout<<"Robot "<< idx<<" crashes into the wall";
        return false;
    }
    if(map[y][x]!=0)
    {
        cout<<"Robot "<<idx<<" crashes into robot "<<map[y][x];
        return false;
    }
    return true;
}

// 상좌하우
int fy[] = {-1,0,1,0};
int fx[] = {0,-1,0,1};
int error=0;
void simulation(int idx, int num, char op){
    for(int i = 0; i<num; i++)
    {
        if(op=='L')
        //상->좌->하->우(0,1,2,3)
        {
            int change_go = robot[idx].go+1;
            if(change_go == 4)  change_go=0;
            robot[idx].go = change_go;
        }
        //상->우->하->좌(0,3,2,1)
        if(op=='R')
        {
            int change_go = robot[idx].go-1;
            if(change_go == -1)  change_go=3;
            robot[idx].go = change_go;
        }
        if(op=='F')
        {
            int ny=robot[idx].y+fy[robot[idx].go];
            int nx=robot[idx].x+fx[robot[idx].go];

            if(isOK(ny,nx, idx)){
                map[robot[idx].y][robot[idx].x]=0;
                map[ny][nx]=idx;
                robot[idx].y=ny;
                robot[idx].x=nx;
            }

            else{
                error=1;
                return;
            }
        }
    }

}

void solution(){
    for(int i = 0; i<op_n; i++)
    {
        int idx, num;
        char op;

        cin>>idx>>op>>num;

        if(!error)
            simulation(idx, num, op);            
    }
    if(!error)
        cout<<"OK";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}