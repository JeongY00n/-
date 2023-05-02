#include<iostream>
#include<vector>
using namespace std;

struct Coord{
    int y,x,num,cnt;
};

int n,m;
int map[10][10];
int copymap[10][10];
int answer = 2e9;
vector<Coord> cctv;

void init(){
    cin>>n>>m;
    for(int y = 1; y<=n; y++)
        for(int x = 1; x<=m; x++)
            {
                cin>>map[y][x];
                if(map[y][x]>=1 && map[y][x]<=5)
                    cctv.push_back({y,x,map[y][x],0});
            }
}
void copy(){
    for(int y = 1; y<=n; y++)
        for(int x = 1; x<=m; x++)
            copymap[y][x]=map[y][x];
}
void Right(int y, int x){
    for(int i = x+1; i<=m; i++)
    {
        if(copymap[y][i]==6)break;
        if(copymap[y][i]>=1 && copymap[y][i]<=5)continue;
        copymap[y][i]=-1;
    }
}
void Left(int y, int x){
    for(int i = x-1; i>=1; i--)
    {
        if(copymap[y][i]==6)break;
        if(copymap[y][i]>=1 && copymap[y][i]<=5)continue;
        copymap[y][i]=-1;
    }
}
void Down(int y, int x){
    for(int i = y+1; i<=n; i++)
    {
        if(copymap[i][x]==6)break;
        if(copymap[i][x]>=1 && copymap[i][x]<=5)continue;
        copymap[i][x]=-1;
    }
}
void Up(int y, int x){
    for(int i = y-1; i>=1; i--)
    {
        if(copymap[i][x]==6)break;
        if(copymap[i][x]>=1 && copymap[i][x]<=5)continue;
        copymap[i][x]=-1;
    }
}
void Check_cctv(){

    for(int idx = 0; idx<cctv.size(); idx++){
        int y = cctv[idx].y;
        int x = cctv[idx].x;
        int num = cctv[idx].num;
        int cnt = cctv[idx].cnt;

        if(num == 1){
            if(cnt==0)
                Right(y,x);
            else if(cnt==1)
                Down(y,x);
            else if(cnt==2)
                Left(y,x);
            else if(cnt==3)
                Up(y,x);
        }
        if(num == 2){
            if(cnt==0||cnt==2)
            {
                Right(y,x);
                Left(y,x);
            }
            else if(cnt==1||cnt==3)
            {
                Down(y,x);
                Up(y,x);
            }
        }
        if(num == 3){
            if(cnt==0)
            {
                Right(y,x);
                Up(y,x);
            }
            else if(cnt==1)
            {
                Right(y,x);
                Down(y,x);
            }
            else if(cnt==2)
            {
                Left(y,x);
                Down(y,x);
            }
            else if(cnt==3)
            {
                Left(y,x);
                Up(y,x);
            }
        }
        if(num == 4){
            if(cnt==0)
            {
                Right(y,x);
                Left(y,x);
                Up(y,x);
            }
            else if(cnt==1)
            {
                Right(y,x);
                Down(y,x);
                Up(y,x);
            }
            else if(cnt==2)
            {
                Right(y,x);
                Left(y,x);
                Down(y,x);
            }
            else if(cnt==3)
            {
                Left(y,x);
                Down(y,x);
                Up(y,x);
            }
        }
        if(num == 5){
            Right(y,x);
            Left(y,x);
            Up(y,x);
            Down(y,x);
        }
    }
}

int Find_answer(){
    int secretarea=0;
    for(int y = 1; y<=n; y++)
        for(int x = 1; x<=m; x++)
        {
            if(copymap[y][x]==0)
                secretarea++;
        }
    return secretarea;
}

void dfs(int idx){
    if(idx==cctv.size())
    {
        copy();
        Check_cctv();
        int secretarea = Find_answer();
        if(answer > secretarea)
            answer = secretarea;
        return;
    }
    cctv[idx].cnt = 0;
    dfs(idx+1);
    cctv[idx].cnt = 1;
    dfs(idx+1);
    cctv[idx].cnt = 2;
    dfs(idx+1);
    cctv[idx].cnt = 3;
    dfs(idx+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(0);
    cout<<answer;
    return 0;
}