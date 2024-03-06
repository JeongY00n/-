#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int N,M,K;
int A[11][11];
int map[11][11];
vector<int> tree[11][11];
void init(){
    cin>>N>>M>>K;
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=N; j++)
        {
            cin>>A[i][j];
            map[i][j]=5;
        }
    
    for(int i = 0; i<M; i++)
    {
        int y,x,age;
        cin>>y>>x>>age;
        tree[y][x].push_back(age);
    }
    
}
void spring_summer(){
    for(int y = 1; y<=N; y++)
    {
        for(int x = 1; x<=N; x++)
        {
            if(tree[y][x].empty())continue;
            sort(tree[y][x].begin(), tree[y][x].end());
            for(int n = 0; n<tree[y][x].size(); n++)
            {
                // 양분을 먹을 수 있는 경우
                if(map[y][x]-tree[y][x][n]>=0)
                {
                    map[y][x]-=tree[y][x][n];
                    tree[y][x][n]++;
                }
                // 먹을 수 없는 경우 죽음 => 양분이 되어버림
                else
                {
                    for(int m=n; m<tree[y][x].size(); m++)
                        map[y][x]+=tree[y][x][m]/2;

                    tree[y][x].erase(tree[y][x].begin()+n,tree[y][x].end());
                    break;
                }
            }
        }
    }
}

void fall(){
    int fy[]={-1,-1,-1,0,0,1,1,1};
    int fx[]={-1,0,1,-1,1,-1,0,1};
    
    for(int y = 1; y<=N; y++)
    {
        for(int x = 1; x<=N; x++)
        {
            if(tree[y][x].empty())continue;
            for(int n = 0; n<tree[y][x].size(); n++)
            {
                // 5의 배수인 경우에만 번식
                if(tree[y][x][n]%5==0)
                {
                    // 번식중
                    for(int i = 0; i<8; i++)
                    {
                        int ny=y+fy[i];
                        int nx=x+fx[i];

                        if(ny<=0||nx<=0||ny>N||nx>N)continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }

}
void winter(){
    for(int y = 1; y<=N; y++)
        for(int x = 1; x<=N; x++)
            map[y][x]+=A[y][x];
}
void solution(){

    for(int i = 0; i<K; i++)
    {
        // 봄 + 여름
        spring_summer();
        // 가을
        fall();
        // 겨울
        winter();
    }

    int answer=0;
    for(int y = 1; y<=N; y++)
    {
        for(int x = 1; x<=N; x++)
        {
            answer+=tree[y][x].size();
        }
    }

    cout<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}