#include<iostream>
#include<queue>
using namespace std;

int L,R,C;
pair<pair<int,int>, pair<int, int>> s,e;
char map[30][30][30];
void init(){
    char temp;
    for(int l=0; l<L; l++)
    {
        for(int r=0; r<R; r++)
            for(int c=0; c<C; c++)
            {
                cin>>map[l][r][c];
                if(map[l][r][c]=='S')
                    s = {{0,l},{r,c}};
                if(map[l][r][c]=='E')
                    e = {{0,l},{r,c}};
            }
    }
}
void bfs(){
    int fl[]={-1,1,0,0,0,0};
    int fr[]={0,0,-1,1,0,0};
    int fc[]={0,0,0,0,-1,1};

    queue<pair<pair<int,int>, pair<int, int>>> q;
    int visited[30][30][30]={0};
    q.push(s);
    visited[s.first.second][s.second.first][s.second.second]=1;

    int time=0;
    while(!q.empty()){
        pair<pair<int,int>, pair<int, int>> now = q.front();
        q.pop();

        int time = now.first.first;
        int l = now.first.second;
        int r = now.second.first;
        int c = now.second.second;
        

        for(int i = 0; i<6; i++)
        {
            int nl = l+fl[i];
            int nr = r+fr[i];
            int nc = c+fc[i];

            if(nl<0||nr<0||nc<0||nl>=L||nr>=R||nc>=C)continue;
            if(map[nl][nr][nc]=='#')continue;
            if(visited[nl][nr][nc]==1)continue;

            if(nl == e.first.second && nr==e.second.first && nc==e.second.second)
            {
                cout<<"Escaped in "<<time+1<<" minute(s).\n";
                return;
            }

            visited[nl][nr][nc]=1;
            q.push({{time+1,nl},{nr,nc}});

        }
    }

    cout<<"Trapped!\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        cin>>L>>R>>C;
        if(L==0&&R==0&&C==0) break;
        init();
        bfs();
    }

    return 0;
}