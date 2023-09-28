#include<iostream>
#include<queue>
using namespace std;

/*
    - 3x3 크기에서 중복이 있는지
        check1[9][10]
        0+0   0+1   0+2
        1*3+0 1*3+1 1*3+2
        2*3+0 2*3+1 2*3+2
    - 세로선에 중복이 있는지
        check2[9][10]
    - 가로선에 중복이 있는지
        check3[9][10]

    계속 진행하다가 답이 될 수 없는 것을 확인하면 이전으로 되돌아가기

*/
char map[9][9];
int check1[9][10], check2[9][10], check3[9][10];

void init(){
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            cin>>map[i][j];

            if(map[i][j]!='0'){
                // 3x3
                check1[i/3*3+j/3][map[i][j]-'0']=1;
                // 세로선
                check2[j][map[i][j]-'0']=1;
                // 가로선
                check3[i][map[i][j]-'0']=1;
            }
        }
    }
}

int end_dfs=0;
void dfs(int y, int x, int cnt){
    if(cnt==81)
    {
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                cout<<map[i][j];
            }
            cout<<"\n";
        }
        end_dfs=1;
    }
    if(end_dfs)return;

    int ny=y,nx=x+1;
    if(nx>=9)
    {
        ny++;
        nx%=9;
    }
    
    if(map[ny][nx]!='0')
        dfs(ny,nx,cnt+1);
    
    else{
        for(int n=1; n<=9; n++)
        {
            if(check1[ny/3*3+nx/3][n]==1)continue;
            if(check2[nx][n]==1)continue;
            if(check3[ny][n]==1)continue;

            map[ny][nx]=n+'0';
            check1[ny/3*3+nx/3][n]=1;
            check2[nx][n]=1;
            check3[ny][n]=1;

            dfs(ny,nx,cnt+1);

            map[ny][nx]='0';
            check1[ny/3*3+nx/3][n]=0;
            check2[nx][n]=0;
            check3[ny][n]=0;
        }
    }
    
}
      
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(0,-1,0);

    return 0;
}

