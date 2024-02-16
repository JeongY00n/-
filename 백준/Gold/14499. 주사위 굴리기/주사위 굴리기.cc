#include<iostream>

using namespace std;

int N,M,y,x,op;
int map[20][20];
void init(){
    cin>>N>>M>>y>>x>>op;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin>>map[i][j];
}

// 명령에 따라 변하는 주사위 위치에 씌여진 숫자
// 위, 아래, 수직방향위, 수직방향아래, 수평방향오, 수평방향왼
int top = 0, bottom=0, ver=0, rever=0, hori=0, rehori=0;
void simul(int dir){
    if(dir==1)// 동
    {
        int a = top;
        top=rehori;
        rehori=bottom;
        bottom=hori;
        hori=a;
    }
    else if(dir==2)// 서
    {
        int a = top;
        top=hori;
        hori=bottom;
        bottom=rehori;
        rehori=a;
    }
    else if(dir==3)// 북
    {
        int a = top;
        top=rever;
        rever=bottom;
        bottom=ver;
        ver=a;
    }
    else if(dir==4)// 남
    {
        int a = top;
        top=ver;
        ver=bottom;
        bottom=rever;
        rever=a;
    }

}
int fy[]={0,0,0,-1,1};
int fx[]={0,1,-1,0,0};
void solution(int dir){
    int ny = y+fy[dir];
    int nx = x+fx[dir];

    if(ny<0||nx<0||ny>=N||nx>=M)return;
    simul(dir);
    if(map[ny][nx]==0)
        map[ny][nx]=bottom;
    else
    {
        bottom=map[ny][nx];
        map[ny][nx]=0;
    }
    // 주사위 위치 갱신
    y = ny;
    x = nx;

    cout<<top<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    for(int i = 0; i<op; i++)
    {
        int dir; cin>>dir;
        solution(dir);
    }
    return 0;
}
