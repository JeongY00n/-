#include<iostream>
#include<vector>
using namespace std;

/*
    직속 상사에게 칭찬을 받은 직원은 부하들에게도 칭찬해주어야한다
    본인의 부하들을 구별해둬야함
*/
int n, m;
vector<int> temp[100001];
int sum[100001], visited[100001];

void solution(int id){
    for(int i = 0; i<temp[id].size(); i++)
    {
        if(visited[temp[id][i]]==1)continue;
        sum[temp[id][i]]+=sum[id];
        visited[temp[id][i]]=1;
        solution(temp[id][i]);
        visited[temp[id][i]]=0;
    }
}
void init(){
    cin>>n>>m;
    // 직속 부하 저장
    for(int i = 1; i<=n; i++)
    {
        // 입력받은 직속 상사 id에 대해
        int id;
        cin>>id;
        if(id == -1) id = 0;
        // i라는 직속 부하 저장
        temp[id].push_back({i}); 
    }
    
    for(int i = 0; i<m; i++)
    {
        int id, w;
        cin>>id>>w;
        sum[id]+=w;
        //solution(id, w); <= 이렇게 하면 칭찬이 진행될 때마다 돌아가야하므로 시간초과 발생
    }
    solution(1); // m번의 칭찬을 통해 직속 상사에게 받은 칭찬 수치가 정해지면, 한 번의 dfs를 통해 내리칭찬 진행

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i = 1; i<=n; i++)
        cout<<sum[i]<<" ";

    return 0;
}