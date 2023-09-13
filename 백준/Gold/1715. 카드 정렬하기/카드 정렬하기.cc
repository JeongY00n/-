#include<iostream>
#include<queue>
using namespace std;

int n, card;
priority_queue<int, vector<int>, greater<int>> pq;
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>card;
        pq.push({card});
    }
}

void solution(){
    int total = 0;
    while(pq.size()>1){
        int card1 = pq.top();
        pq.pop();
        int card2 = pq.top();
        pq.pop();
        total += (card1+card2);
        pq.push({card1 + card2});
    }
    
    cout<<total;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
    
}