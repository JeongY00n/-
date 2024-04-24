#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M;
vector<int> map[201];
vector<int> path;
void init(){
    cin>>N>>M;

    // 도시의 연결 정보
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            int temp; cin>>temp;
            if(temp==1)
                map[i].push_back(j);
        }
    }

    // 여행 계획
    for(int i = 0; i<M; i++)
    {
        int idx; cin>>idx;
        path.push_back(idx);
    }

}

bool canGo(int start, int end){
    queue<int> q;
    q.push(start);

    int visited[201]={0};
    visited[start]=1;

    while(!q.empty()){
        int now = q.front(); q.pop();

        for(int i = 0; i<map[now].size(); i++)
        {
            if(visited[map[now][i]])continue;
            if(map[now][i]==end)
            {
                return true;
            }
            visited[map[now][i]]=1;
            q.push({map[now][i]});
        }
    }
    return false;
}

void solution(){
    for(int i=0; i<M-1; i++)
    {
        if(path[i]==path[i+1])continue;
        // 갈 수 없는 경우 NO 출력하고 중단
        if(!canGo(path[i],path[i+1]))
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}