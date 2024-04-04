#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;


/*
    가스관과 빵집을 연결하는 파이프라인의 최대 개수
    방향이 여러개
    위로 갈 수 있는 상황이 된다면 위로 올라간다=>아래 가스관과 빵집을 연결하는데 최대한 방해가 되지 않도록


    ==> 재귀함수에 idx(가스관번호)를 넣지 않고 dfs(y,x,idx,cnt)
        반복문을 통해서 재귀함수의 y값에 idx(가스관 번호) 부여 dfs(y,x)
*/

int R,C;
char map[10000][500];
void init(){
    cin>>R>>C;
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            cin>>map[i][j];
}

int fy[]={-1,0,1}, fx[]={1,1,1}; // 오.위.대, 오, 오.아.대
int visited[10000][500], check[10000], end_flag;
int dfs(int y, int x){
    visited[y][x]=1;
    
    if(x==C-1)
    {
        end_flag=1;
        return 1;
    }

    for(int i = 0; i<3; i++)
    {
        int ny=y+fy[i], nx=x+fx[i];
        if(ny<0||nx<0||ny>=R||nx>=C)continue;

        // 파이프를 설치할 수 없는 건물이 위치해있거나 다른 파이프가 이미 지나간 적이 있는 경우
        if(map[ny][nx]=='x' || visited[ny][nx])continue;
        
        dfs(ny,nx);
        if(end_flag)return 1;
    }

    return 0;

}

void solution(){
    int answer=0;
    for(int i = 0; i<R; i++)
    {
        end_flag=0;
        if(dfs(i,0))
            answer++;
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}
