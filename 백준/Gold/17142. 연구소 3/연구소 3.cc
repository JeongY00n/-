#include<iostream>
#include<vector>
#include <queue>

using namespace std;

/*
    모든 빈칸에 바이러스를 퍼뜨리는 최소 시간

    * M개의 활성 바이러스 선택
    * 빈 칸마다 활성 바이러스로 채워질때까지의 시간을 저장
    * 모든 빈 칸에 바이러스가 퍼졌을 때의 시간을 저장

*/

int N,M,map[50][50];
int zero;
vector<pair<int, int>> virus;
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin>>map[i][j];
            // 활성 바이러스 위치 저장
            if(map[i][j]==2)
                virus.push_back({i,j});
            if(map[i][j]==0)
                zero++;
        }
    }
}
vector<pair<int, int>> v;

int answer=-1;
void solution(){
    queue<pair<int,pair<int, int>>> q; // 선택된 활성 바이러스 큐에 저장
    int visited[50][50]={0};
    for(int i = 0; i<v.size(); i++)
    {
        q.push({0,{v[i].first, v[i].second}});
        visited[v[i].first][v[i].second]=1;
    }

    int dy[]={-1,1,0,0};
    int dx[]={0,0,-1,1};
    
    int cnt=0;
    while(!q.empty()){
        pair<int,pair<int, int>> now = q.front();
        q.pop();

        int time=now.first;
        int y=now.second.first;
        int x=now.second.second;

        // answer에 저장된 최소시간보다 더 걸린다면 진행 중단
        if(time>=answer && answer!=-1)return;
        // 빈 공간에서 바이러스로 채워진 공간 개수 확인
        if(map[y][x]!=2)
            cnt++;
        // 빈 공간을 모두 채운 경우 answer에 time 저장 후 종료
        if(cnt==zero)
            answer = time;
        // 바이러스 퍼뜨리기
        for(int i = 0; i<4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny<0||nx<0||ny>=N||nx>=N)continue;
            if(visited[ny][nx]!=0)continue;
            if(map[ny][nx]==1)continue;
            //cout<<ny<<","<<nx<<","<<time<<"\n";
            // cout<<time<<"\n";
            visited[ny][nx]=1;
            q.push({time+1,{ny,nx}});
        }
    }
    
}
void Combi(int id, int cnt){
    if(cnt==M)
    {
        solution();
        return;
    }
    for(int i = id; i<virus.size(); i++)
    {
        int y = virus[i].first;
        int x = virus[i].second;
        v.push_back({y,x});
        Combi(i+1,cnt+1);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    Combi(0,0);
    cout<<answer;

    return 0;
}