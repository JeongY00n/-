#include<iostream>
#include<algorithm>
using namespace std;

/*
    가희가 볼 수 있는 건물의 개수에 맞춰 최대높이의 건물을 계산
    단비가 볼 수 있는 건물의 개수에 맞춰 최대높이의 건물을 계산

    두 높이중 더 큰 값을 선택
    최대한 단비쪽에 큰 수 배치
*/

int N,G,D;
void init(){
    cin>>N>>G>>D;
}
void solution(){
    if(G+D>N+1)
    {
        cout<<-1;
        return;
    }

    int maxi = max(G,D);

    if(G==1)
        cout<<maxi<<" ";
    else
        cout<<1<<" ";

    for(int i = 1; i<=N-(G-1)-D; i++)
        cout<<1<<" ";
    for(int i = 2; i<=G-1; i++)
        cout<<i<<" ";
    if(G>1)
        cout<<maxi<<" ";
    for(int i = D-1; i>=1; i--)
        cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}