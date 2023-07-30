#include<iostream>
#include<algorithm>
using namespace std;

/*
    가장 가까운 공유기 사이의 거리가 최대...

    1 2 4 8 9
    -   -   -
    -   - - 
    
    공유기 사이의 거리를 정해두고, 이분탐색 진행
    특정 거리 간격의 공유기 수가 몇 개가 되는지 확인
*/

int n, c;
long long x[200000], answer;
void init(){
    cin>>n>>c;
    for(int i = 0; i<n; i++)
        cin>>x[i];
    sort(x, x+n);
}

void solution(){
    long long left=0, right=x[n-1]-x[0];

    while(left<=right)
    {
        int prev=0;
        long long cnt=1, mid = (right+left)/2;

        // 임의로 지정한 거리보다 큰 경우
        // prev 값 갱신
        for(int i = 0; i<n; i++)
        {
            if(x[i]-x[prev]>=mid)
            {
                cnt++;
                prev = i;
            }
        }
        // cnt가 공유기의 갯수보다 크거나 같은 경우
        // 임의로 지정한 거리가 부족하다는 의미이므로 left = mid + 1
        // 큰 경우의 경우에서 임으로 공유기 갯수 만큼 줄여도 정답에는 변화없음
        if(cnt>=c)
        {
            left = mid+1;
            answer = max(answer, mid);
        }
        else
            right = mid-1;

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