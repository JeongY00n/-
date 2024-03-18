#include<iostream>
#include<queue>
using namespace std;

/*
    본인보다 큰 사람이 왼쪽이 몇명이 있는지
    1을 기준으로 
    5개(6,0)(2,1)(3,2)(3,4)(7,3)(5,4)(1,6) 1개
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin>>N;
    int order[11];
    for(int i = 1; i<=N; i++)
        cin>>order[i];
    
    deque<int> temp;
    for(int i = N; i>=1; i--)
    {
        deque<int> front;
        for(int j = 0; j<order[i]; j++)
        {
            front.push_back(temp.front());
            temp.pop_front();
        }
        temp.push_front(i);
        for(int j = 0; j<order[i]; j++)
        {
            temp.push_front(front.back());
            front.pop_back();
        }
    }
    for(int i = 0; i<N; i++)
        cout<<temp[i]<<" ";
    return 0;
}