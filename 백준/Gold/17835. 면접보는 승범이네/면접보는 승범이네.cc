#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct NODE {
    int to;
    long long cost;

    bool operator<(const NODE& other) const {
        return this->cost > other.cost;  
    }
};

int n,m,k;
vector<NODE> v[100001];
long long dp[100001];
priority_queue<NODE> pq;
void init(){
    cin>>n>>m>>k;
    for(int i = 0; i<m; i++)
    {
        int to,from;
        long long cost;
        cin>>to>>from>>cost;
        v[from].push_back({to, cost});
    }

    fill(&dp[0], &dp[100001], 2e18);
    
    for(int i = 0; i<k; i++)
    {
        int a;
        cin>>a;
        pq.push({a,0});
        dp[a]=0;
    }
    
}

void solution(){

    while(!pq.empty()){
        NODE now = pq.top();
        pq.pop();

        int from = now.to;
        if(dp[from]<now.cost)continue;

        for(int i = 0; i<v[from].size(); i++)
        {
            int to = v[from][i].to;
            long long cost = v[from][i].cost;

            if(dp[to] <= dp[from] + cost)continue;
            dp[to] = dp[from] + cost;
            pq.push({to, dp[to]});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    long long maxi=0; // cost
    int maxicity;
    for(int i = 1; i<=n; i++)
    {
        if(maxi < dp[i])
        {
            maxi = dp[i];
            maxicity = i;
        }
    }

    cout<<maxicity<<"\n";
    cout<<maxi;

    return 0;
}