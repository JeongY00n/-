#include<iostream>
#include<queue>
using namespace std;

/*
    dfs
*/


int N,M;
char map[20][20];
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin>>map[i][j];
}
int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
int check[27]={0};
int answer=1;
void solution(int y, int x, int cnt){
    answer = max(answer, cnt);

    for(int i = 0; i<4; i++)
    {
        int ny=y+fy[i];
        int nx=x+fx[i];

        if(ny<0||nx<0||ny>=N||nx>=M)continue;
        if(check[map[ny][nx]-'A']==1)continue;
        check[map[ny][nx]-'A']=1;
        solution(ny,nx,cnt+1);
        check[map[ny][nx]-'A']=0;
    }

    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    check[map[0][0]-'A']=1;
    solution(0,0,1);
    cout<<answer;
    return 0;
}