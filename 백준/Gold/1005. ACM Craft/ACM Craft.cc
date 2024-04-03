#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

struct INFO{
    int sumTime, idx;

    bool operator<(const INFO&other)const{
        return sumTime>other.sumTime;
    }
};
int N,K,W;
int d[1001];
priority_queue<pair<int, int>> pq[1001];
priority_queue<INFO> q;
int cnt[1001];
void init(){

    // 초기화
    for(int i = 1; i<=N; i++)
        pq[i] = priority_queue<pair<int, int>>();
    q = priority_queue<INFO>();
    memset(cnt, 0, sizeof(cnt));


    // 입력
    cin>>N>>K;
    for(int i = 1; i<=N; i++)
        cin>>d[i];
    for(int i = 0; i<K; i++)
    {
        int a,b; cin>>a>>b; //a를 지은 다음에 b를 지어야함
        pq[a].push({d[b], b});
        cnt[b]++; // b를 짓기 전에 지어야할 건물의 개수
    }
    cin>>W;

    for(int i = 1; i<=N; i++)
        if(cnt[i]==0)
            q.push({d[i], i});
}
     
void solution(){
    
    while(!q.empty()){
        int time = q.top().sumTime;
        int idx = q.top().idx;
        q.pop();
        
        if(idx==W) 
        {
            cout<<time<<"\n";
            break;
        }
        while(!pq[idx].empty()){
            cnt[pq[idx].top().second]--;
            if(cnt[pq[idx].top().second])
            {
                pq[idx].pop();
                continue;
            }
            q.push({time+pq[idx].top().first, pq[idx].top().second});
            pq[idx].pop();
            
        }
        //cout<<time<<" ";
    }
}

// 1-2-4-5-7-8
// 1-3-6-7-8

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    for(int tc=0; tc<T; tc++)
    {
        init();
        solution();
    }

    return 0;
}