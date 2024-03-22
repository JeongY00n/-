#include<iostream>
#include<algorithm>
using namespace std;

/*
    먹을 수 있는 범위에 있는 햄버거 중에서
    가능한 다른 사람에게서 먼 위치에 있는 햄버거를 고르기 => 왼쪽부터 탐색
*/
int N,K;
string str;
void init(){
    cin>>N>>K;
    cin>>str;
}
void solution(){
    int answer=0;
    for(int i = 0; i<N; i++)
    {
        if(str[i]!='P')continue;
        for(int j = i-K; j<=i+K; j++)
        {
            if(j<0||j>=N)continue;
            if(str[j]=='H')
            {
                str[j]='_';
                answer++;
                break;
            }
        }
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    return 0;
}