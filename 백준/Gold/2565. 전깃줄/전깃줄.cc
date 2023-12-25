#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n;
vector<pair<int, int>> v;
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
}
void solution(){
    int ans=2e9;
    int dp[100]={0};

    for(int i = 0; i<n; i++){
        dp[i]=1;
        for(int j = 0; j<i; j++){
            if(v[i].second>v[j].second)
            {
                if(dp[i]<=dp[j])
                    dp[i]=dp[j]+1;
            }
        }
        ans = min(ans, n-dp[i]);
    }

    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}