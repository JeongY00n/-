#include<iostream>
#include<algorithm>
using namespace std;


/*
    가스관과 빵집을 연결하는 파이프라인의 최대 개수
    방향이 여러개
    위로 갈 수 있는 상황이 된다면 위로 올라간다=>아래 가스관과 빵집을 연결하는데 최대한 방해가 되지 않도록
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
int visited[10000][500], check[10000], answer, end_flag;
void dfs(int y, int x, int idx, int cnt){
    if(check[idx])return;
    // 마지막 가스관까지 탐색이 끝난 경우
    if(idx==R) 
    {
        answer = cnt;
        end_flag=1;    
        return;
    }
    
    for(int i = 0; i<3; i++)
    {
        int ny=y+fy[i], nx=x+fx[i];
        if(ny<0||nx<0||ny>=R||nx>=C)continue;
        // 파이프를 설치할 수 없는 건물이 위치해있는 경우
        if(map[ny][nx]=='x')continue;
        // 다른 파이프가 이미 지나간 적이 있는 경우
        if(visited[ny][nx])continue;
        visited[ny][nx]=1;
        // 원웅이의 빵집에 가스를 연결했다면 파이프라인 개수에 +1
        // 첫번째 열의 다음 행에서 시작
        if(nx==C-1)
        {
            check[idx]=1;
            dfs(idx+1, 0, idx+1, cnt+1);
            break;
        }
        else
            dfs(ny,nx,idx,cnt);

        if(end_flag)return;
    }
    // 해당 가스관에 빵집을 연결하지 못한 경우
    // 다음 가스관으로 이동
    if(x==0&&!check[idx])
        dfs(idx+1, 0, idx+1, cnt);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(0,0,0,0);
    cout<<answer;

    return 0;
}