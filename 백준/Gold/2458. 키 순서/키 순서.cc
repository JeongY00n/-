#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
    본인보다 큰 학생과 작은 학생을 알아야함
    edge
    갯수를 확인하여 총 합이 n-1인지 확인
    from < to
*/

int n,m;
vector<int> bigger[501], shorter[501];
void init(){
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int from, to;
        cin>>from>>to;
        bigger[from].push_back({to});
        shorter[to].push_back({from});
    }
}

int b_cnt[501], s_cnt[501];
int visited[501];
void BIGGER(int num, int idx){
    for(int i = 0; i<bigger[idx].size(); i++)
    {
        if(visited[bigger[idx][i]]!=0)continue;
        visited[bigger[idx][i]]=1;
        b_cnt[num]++;
        BIGGER(num, bigger[idx][i]);
    }
}

void SHORTER(int num, int idx){
    for(int i = 0; i<shorter[idx].size(); i++)
    {
        if(visited[shorter[idx][i]]!=0)continue;
        visited[shorter[idx][i]]=1;
        s_cnt[num]++;
        SHORTER(num, shorter[idx][i]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int answer=0;
    for(int i = 1; i<=n; i++)
    {
        memset(visited, 0, sizeof(visited));
        BIGGER(i,i);
        memset(visited, 0, sizeof(visited));
        SHORTER(i,i);
    }
    for(int i = 1; i<=n; i++)
    {
        if(b_cnt[i]+s_cnt[i]==n-1) answer++;
    }
    cout<<answer;
    return 0;
}