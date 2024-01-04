#include<iostream>
#include<queue>
using namespace std;

int soo, sis;

void bfs(){
    queue<pair<int, int>> q;
    q.push({soo, 0});
    int check[100001]={};

    int time=2e9;
    int answer=0;

    // 처음 도착한 이후로는 모두 time보다 큰, 더 느리게 도착한 경우이므로
    // queue에 새롭게 저장할 필요가 없으므로 동생에게 도착한 이후에는 queue에 저장하지 않음
    int flag=0;

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        int n = now.first;
        int cnt = now.second;

        check[n]=1;
        if(n==sis && time>=cnt)
        {
            time=cnt;
            answer++;
            flag=1;
        }
            

        if(!flag){
            
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
        

    }
    cout<<time<<"\n"<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>soo>>sis;
    bfs();


    return 0;
}