#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    오고 가는 최장시간
    도로 시작점 , 끝점, 도로 지나는데 필요한 시간
    edge (시작점, 끝점, 시간)
    배열 인덱스를 시작점으로 설정하고,
    끝점, 시간 정보 저장
    목적지 도달하면 다시 되돌아가는 것 까지 계산
    각 학생들의 최단 거리 저장
    저장된 최단 거리 중 가장 오래 걸리는 학생의 소요시간을 출력
*/

struct Edge{
    int to, time;
};

struct cmp{
    bool operator()(Edge a, Edge b){
        if(a.time < b.time)return false;
        if(a.time > b.time)return true;
        return false;
    }
};

int n,m,x;
vector<Edge> v[1001];
int go_party[1001], go_home[1001];
int mini[1001][1001];
void init(){
    cin>>n>>m>>x;
    for(int i = 0; i<m; i++){
        int from, to, time;
        cin>>from>>to>>time;
        v[from].push_back({to, time});
    }
    fill(&mini[1][1], &mini[1000][1000], 2e9);
}
void solution(int to){
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.push({to, 0});
    while(!q.empty()){
        Edge now = q.top();
        q.pop();

        int from = now.to;
        int time = now.time;


        for(int i = 0; i<v[from].size(); i++){

            if(mini[to][v[from][i].to] > time+v[from][i].time)
            {
                mini[to][v[from][i].to]=time+v[from][i].time;
                q.push({v[from][i].to, time+v[from][i].time});
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    init();

    for(int i =1; i<=n; i++)    
        solution(i);

    for(int i = 1; i<=n; i++)
    {
        if(i!=x)
            answer = max(answer, mini[i][x]+mini[x][i]);
    }
    
    cout<<answer;

    return 0;
}