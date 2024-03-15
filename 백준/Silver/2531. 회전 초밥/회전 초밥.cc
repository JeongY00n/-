#include<iostream>
#include<algorithm>
using namespace std;

/*
먹을 수 있는 초밥의 최대 가짓수

*/
int N,d,k,c;
int sushi[30000];
void init(){
    cin>>N>>d>>k>>c;
    for(int i = 0; i<N; i++)
        cin>>sushi[i];
}

void solution(){
    int answer=0;
    int start=0,last=k-1;
    int check[30001]={0}, cnt=0;

    // 처음 0부터 k-1까지의 먹은 개수 세팅
    for(int i = start; i<=last; i++)
    {
        if(check[sushi[i]]==0)
            cnt++;
        check[sushi[i]]++;
    }
    // 먹은 초밥의 종류중에서 c가 없는 경우와 있는 경우
    if(check[c]==0)
        answer = cnt+1;
    else
        answer = cnt;


    while(start<N-1)
    {
        check[sushi[start]]--;
        if(check[sushi[start]]==0)
            cnt--;
        start++;

        last++;
        last%=N; // last값이 N을 넘어가는 경우에 대해 처리 해주기

        if(check[sushi[last]]==0)
            cnt++;
        check[sushi[last]]++;

        if(check[c]==0)
            answer = max(answer,cnt+1);
        else
            answer = max(answer,cnt);       
    }

    cout<<answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    solution();

    return 0;
}