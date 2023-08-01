#include<iostream>
#include<algorithm>
using namespace std;

/*
    연속으로 초밥을 먹음(가능한 다양한 종류로)
    연속으로 초밥을 먹었을 때,
    - 쿠폰에 적힌 초밥을 먹은 경우
    - 쿠폰에 적힌 초밥을 안먹은 경우

*/

int n,d,k,c;
int susi[3000000];
int eat_cnt[3001];
int answer;
void init(){
    cin>>n>>d>>k>>c;
    for(int i = 0; i<n; i++)
        cin>>susi[i];
}

// 2 9 25 7 7 9 2 30
// - -  - -
//   -  - - -
//      - - - -
// - -  -          -
void solution(){
    int left=0,cnt=0,num=0;

    // 인덱스 0 부터의 구간 합 계산
    for(int i = 0; i<k; i++)
    {
        num = susi[i];
        if(eat_cnt[num]==0)cnt++;
        eat_cnt[num]++;
    }

    if(eat_cnt[c]==0) answer = max(answer, cnt+1);
    else answer = max(answer, cnt);

    // 앞에서 계산한 구간합에 대해 한 칸씩 이동하면서 최댓값 계산
    while(left<=n)
    {
        num = susi[left];
        eat_cnt[num]--;
        if(eat_cnt[num]==0)cnt--;

        num = susi[(left+k)%n];
        eat_cnt[num]++;
        if(eat_cnt[num]==1)cnt++;

        left = left+1;

        if(eat_cnt[c]==0) answer = max(answer, cnt+1);
        else answer = max(answer, cnt);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    solution();
    cout<<answer;

    return 0;
}