#include<iostream>
#include<algorithm>
using namespace std;

/*
입력된 수열에 대해 오름차순으로 정렬
수열에서 두 수 선택 -> 투 포인터 사용하기
*/

int n, m, answer = 2e9;
int a[100000];

void init(){
    cin>>n>>m;
    for(int i = 0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
}

void solution(){
    int right=1, left=0;
    int diff=0;
    
    while(left!=n){
        diff = a[right]-a[left];
        if(m == diff)
        {
            answer = m;
            return;
        }
        // m의 값보다 diff 값이 더 큰 경우라면
        // left의 값에 +1
        // ( a[left] 보다 큰 값과 a[right] 비교하기 위함 )
        else if(m < diff)
        {
            answer = min(answer, diff);
            left++;
            continue;
        }
        right++;
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