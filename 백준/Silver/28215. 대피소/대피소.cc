#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
    
*/
int N,K;
vector<pair<int, int>> v;
int check[51];
void init(){
    cin>>N>>K;
    for(int i = 0; i<N; i++)
    {
        int y,x;
        cin>>y>>x;
        v.push_back({y,x});
    }
}

int dist(){
    int maxi = 0;
    for(int i=0; i<N; i++)
    {
        if(check[i]==0)
        {
            int mini = 2e9;
            int y1 = v[i].first;
            int x1 = v[i].second;

            for(int j = 0; j<N; j++)
            {
                if(i==j)continue;
                if(check[j]==0)continue;

                int y2 = v[j].first;
                int x2 = v[j].second;

                mini = min(mini, abs(y1-y2)+abs(x1-x2));
            }
            maxi = max(maxi, mini);
        }
    }
    return maxi;
}

int answer = 2e9;
void Combi(int idx, int cnt){
    if(cnt == K)
    {
        answer = min(answer, dist());
        return;
    }

    for(int i = idx; i<N; i++)
    {
        check[i]=1;
        Combi(i+1, cnt+1);
        check[i]=0;
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