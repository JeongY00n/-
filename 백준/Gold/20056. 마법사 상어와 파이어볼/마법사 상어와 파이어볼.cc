#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Coord{
    int y,x,m,s,d;
};
int N,M,K;
queue<Coord> q;
int answer=0;
void init(){
    cin>>N>>M>>K;
    for(int i = 0; i<M; i++)
    {
        int y,x,m,d,s;
        cin>>y>>x>>m>>s>>d;
        q.push({y,x,m,s,d});
    }
}

void solution(){
    int fy[]={-1,-1,0,1,1,1,0,-1};
    int fx[]={0,1,1,1,0,-1,-1,-1};

    queue<Coord> map[51][51];

    answer=0;

    while(!q.empty()){
        Coord now = q.front();
        q.pop();

        int ny = now.y+fy[now.d]*now.s;
        int nx = now.x+fx[now.d]*now.s;

        // if(ny>0)
        // {
        //     ny=ny%N;
        //     if(ny==0) ny=N;
        // }
        // else
        // {
        //     ny=(abs(ny)+2)%N;
        //     if(ny==0) ny=N;
        // }
        // if(nx>0)
        // {
        //     nx=nx%N;
        //     if(nx==0) nx=N;
        // }
        // else
        // {
        //     nx=(abs(nx)+2)%N;
        //     if(nx==0) nx=N;
        // }

        while(nx < 1) nx += N; // 주의!! if문 만으로는 안된다
        while(ny < 1) ny += N;
        while(nx > N) nx -= N;
        while(ny > N) ny -= N;
        
        // 11 12 13 14
        // 7 8 9 10
        // 3 4 5 6
        //   0 1 2        
        // 1 2 3 4
        // 5 6 7 8 

        map[ny][nx].push({ny,nx,now.m,now.s,now.d});
    }

    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            if(map[i][j].empty())continue;
            int size = map[i][j].size();
            if(size>=2)  // 같은 칸에 파이어볼이 2개 이상인 경우
            {
                int m_sum=0;
                int s_sum=0;
                int flag=0; // 모두 짝수 : 2, 모두 홀수 : 3, 그렇지 않으면 : 1
                
                while(!map[i][j].empty()){
                    Coord now = map[i][j].front();
                    map[i][j].pop();

                    m_sum+=now.m;
                    s_sum+=now.s;
                    if(now.d%2==0) // 짝수
                    {
                        if(flag==3 || flag==1)
                            flag=1;
                        else
                            flag=2;
                    }
                    if(now.d%2!=0) // 홀수
                    {
                        if(flag==2 || flag==1)
                            flag=1;
                        else
                            flag=3;
                    }
                }

                if(m_sum/5==0)continue; // 질량이 0인 파이어볼인 경우

                int dir_e[]={0,2,4,6};
                int dir_o[]={1,3,5,7};

                for(int n = 0; n<4; n++)
                {
                    if(flag==2||flag==3)
                        q.push({i,j,m_sum/5,s_sum/size,dir_e[n]});
                    else
                        q.push({i,j,m_sum/5,s_sum/size,dir_o[n]});
                    answer+=m_sum/5;
                }
            }
            else
            {
                q.push(map[i][j].front());
                answer+=map[i][j].front().m;
                // cout<<map[i][j].front().m;
                map[i][j].pop();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i = 0; i<K; i++)
        solution();

    cout<<answer;

    return 0;
}