#include<iostream>
#include<queue>
using namespace std;
int soo, sis;


void bfs(){
    queue<pair<int, int>> q;
    q.push({soo, 0});
    int check[100001]={0};
    check[soo]=1;

    int visit_time=2e9;
    int answer=0;

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        int n = now.first;
        int cnt = now.second;
        check[n]=cnt;

        if(n==sis && visit_time==cnt)
            answer++;

        if(n==sis && visit_time > cnt)
        {
            visit_time=cnt;
            answer=1;
        }
        
        if(n-1>=0)
        {
            if(!check[n-1])
                q.push({n-1, cnt+1});
            
        }
        if(n+1<=100000)
        {
            if(!check[n+1])
                q.push({n+1, cnt+1});
        }
        if(n*2<=100000)
        {
            if(!check[n*2])
                q.push({n*2, cnt+1});
        }

    }
    cout<<visit_time<<"\n"<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>soo>>sis;
    bfs();


    return 0;
}