#include<iostream>

using namespace std;

int N,M;
int map[50][50];
int y,x,d;
int answer=0;
void init(){
    cin>>N>>M;
    cin>>y>>x>>d;

    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin>>map[i][j];
}

int fy[]={-1,0,1,0};
int fx[]={0,1,0,-1};
void solution(){
    int cnt=0; // 주변 4칸 중 청소되지 않은 칸 확인
    while(1){
        
        cnt=0;
        // 청소
        if(map[y][x]==0)
        {
            answer++;
            map[y][x]=-1; // 청소 완료
        }

        // 주변 4칸 확인
        int dir=d;
        for(int i = 0; i<4; i++)
        {
            dir=dir-1;
            if(dir<0)dir=3;
            int ny=y+fy[dir];
            int nx=x+fx[dir];

            // 이동
            if(map[ny][nx]==0)
            {
                cnt=0;
                y = ny;
                x = nx;
                d=dir;
                break;
            }
            
            cnt++; // 청소되어있거나 벽인 경우
        }

        if(cnt!=0)// 주변 청소할 칸이 없음
        {
            int ny = y+fy[d]*-1;
            int nx = x+fx[d]*-1;

            if(map[ny][nx]==1) // 후진이 불가한 경우 중단
                return;
            
            y = ny; x = nx;
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