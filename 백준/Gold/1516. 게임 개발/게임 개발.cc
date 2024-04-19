#include<iostream>
#include<queue>

using namespace std;

struct INFO
{
    int idx, time;

    bool operator<(const INFO&other) const{
        return time>other.time;
    }
};

int N, build[501], cnt[501], answer[501];
queue<int> temp[501];

void init(){
    cin>>N;
    for(int i = 1; i<=N; i++)
    {
        cin>>build[i];
        int idx=0;
        while(1)
        {
            cin>>idx;
            if(idx==-1)break;
            cnt[i]++;
            temp[idx].push(i);
        }
    }
}
void solution(){
    priority_queue<INFO> q;

    for(int i = 1; i<=N; i++)
    {
        if(cnt[i]==0)
        {
            q.push({i,build[i]});
            answer[i]=build[i];
        }
    }
    
    while(!q.empty()){
        INFO now = q.top(); q.pop();

        int idx=now.idx, time=now.time;

        while(!temp[idx].empty())
        {
            int next=temp[idx].front();
            cnt[next]--;
            if(cnt[next]==0)
            {
                q.push({next, time+build[next]});
                answer[next]=time+build[next];
            }
            temp[idx].pop();
        }
    }

}

void print_answer(){
    for(int i = 1; i<=N; i++)
        cout<<answer[i]<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    print_answer();

    return 0;
}