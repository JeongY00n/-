#include<iostream>
#include<algorithm>
using namespace std;


int N, num[2250000]={0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i = 0; i<N*N; i++)
        cin>>num[i];

    sort(num,num+N*N,greater<>());

    cout<<num[N-1];

    return 0;
}