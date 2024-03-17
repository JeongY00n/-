#include<iostream>
#include<queue>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i = 0; i<N*N; i++)
    {
        int num; cin>>num;
        if(pq.size()<N)
            pq.push(num);
        else
        {
            if(pq.top()<num)
            {
                pq.pop();
                pq.push(num);
            }
        }
    }

    cout<<pq.top();

    return 0;
}