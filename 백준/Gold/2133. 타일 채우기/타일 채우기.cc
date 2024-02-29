#include<iostream>
#include<cmath>
using namespace std;

/*
    dp
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin>>N;
    if(N%2==0)
    {
        int DP[31]={0};
        DP[2]=3;
        for(int i = 4; i<=N; i+=2)
        {
            DP[i]=DP[i-2]*DP[2];

            int idx=i-2; 
            while(idx>2) // 다음 조합에서 이전 조합과의 중복을 제외한 경우들의 합을 계산
            {
                idx-=2;
                DP[i]+=DP[idx]*2;
            }
            DP[i]+=2; // 각 크기마다의 특수한 모양
        }
        cout<<DP[N];
    }
    else
        cout<<0;

    return 0;
}