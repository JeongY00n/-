#include<iostream>
#include<queue>

using namespace std;

/*
    * 탐색방향 : 상하좌우,대각선

    * 방문처리
    * 주변 칸을 탐색하고 조건에 맞으면 큐에 저장
    * 높이가 0이면 큐에 넣지 않음
    * O(N*M)=100*70
*/

int N,M,map[100][70];
priority_queue<pair<int, pair<int, int>>> pq;
void init(){
    cin>>N>>M;

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin>>map[i][j];
            // 내림차순 정렬(높은 격자를 우선순위로 정렬)
            pq.push({map[i][j],{i,j}});
        }    

    }
}
int visited[100][70];
int dy[]={-1,-1,-1,0,1,1,1,0}, dx[]={-1,0,1,1,1,0,-1,-1};
void Check(int y, int x){
    queue<pair<int, int>> q;
    q.push({y,x});
    visited[y][x]=1;

    while(!q.empty()){
        pair<int, int> now = q.front(); q.pop();

        for(int i = 0; i<8; i++)
        {
            int ny = now.first+dy[i], nx = now.second+dx[i];
            if(ny<0||nx<0||ny>=N||nx>=M)continue;
            
            // 격자의 높이가 0이거나 현재 격자의 높이보다 큰 경우는 지나감
            if(map[ny][nx]==0||map[ny][nx]>map[now.first][now.second])continue;
            
            if(visited[ny][nx])continue;
            visited[ny][nx]=1;

            q.push({ny,nx});
        }
    }
}
void solution(){
    int answer=0;
    while(!pq.empty())
    {
        int y=pq.top().second.first, x=pq.top().second.second;
        pq.pop();
        if(map[y][x]!=0)
        {
            if(visited[y][x])continue;
            Check(y,x);
            answer++;
        }
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