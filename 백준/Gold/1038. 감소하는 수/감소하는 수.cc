#include<iostream>
#include<queue>
using namespace std;
long long answer;
int n, cnt = -1;
void solution(){
    queue<long long> q;
    for(int i = 0; i<=9; i++)
    {
        q.push(i);
        cnt++;
        if(cnt == n)
        {
            answer = i;
            return;
        }
    }

    while(!q.empty()){
        long long now = q.front();
        q.pop();

        int last_num = now%10;

        for(int i = 0; i<last_num; i++)
        {
            long long num = now*10+i;
            q.push(num);
            cnt++;
            if(cnt == n)
            {
                answer = num;
                return;
            }
        }
    }
    if(cnt < n)
        answer = -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    solution();
    cout<<answer;
    return 0;
}