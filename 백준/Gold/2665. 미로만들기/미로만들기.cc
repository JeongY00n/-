#include<iostream>
#include<queue>
using namespace std;

char map[50][50];
int n;
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin>>map[i][j];
}

void solution(){
    // pair 에서 첫번째 데이터에 대해 오름차순으로 정렬 (검은방을 적게 제거한 순으로 정렬)
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> q;
    q.push({0,{0,0}});

    int visited[50][50]={0};
    visited[0][0]=1;

    int fy[]={-1,1,0,0};
    int fx[]={0,0,-1,1};

    int answer=0;

    while(!q.empty()){
        pair<int, pair<int,int>> now = q.top();
        q.pop();

        int y = now.second.first;
        int x = now.second.second;
        int cnt = now.first;

        for(int i = 0; i<4; i++)
        {
            int ny = fy[i]+y;
            int nx = fx[i]+x;

            // 끝방에 도착한 경우 종료
            if(ny==n-1&& nx==n-1) 
            {
                cout<<cnt;
                return;
            }

            if(ny<0||nx<0||ny>=n||nx>=n)continue;
            if(visited[ny][nx]==1)continue;
            visited[ny][nx]=1;

            if(map[ny][nx]=='0') // 검은방
                q.push({cnt+1,{ny,nx}});
            
            else // 흰방
                q.push({cnt, {ny,nx}});
        }

    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}