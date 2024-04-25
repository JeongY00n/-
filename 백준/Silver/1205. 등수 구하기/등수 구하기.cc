#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,score,P; cin>>N>>score>>P;
    // 오름차순
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i<N; i++)
    {
        int a; cin>>a;
        pq.push(a);
    }

    int rank=1;
    if(pq.size()==P && pq.top()>=score)
        rank=-1;
    else
    {
        while(!pq.empty()){
            if(pq.top()<=score)
                pq.pop();
            else
                break;
        }
        rank=rank+pq.size();
    }
    
    cout<<rank;


    return 0;
}