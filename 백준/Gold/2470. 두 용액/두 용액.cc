#include<iostream>
#include<algorithm>
using namespace std;
/*
두 수 선택
투 포인터 사용
오름차순으로 정렬
*/
int n, arr[100000];
int liq1, liq2;
int answer=2e9;

void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }   
    sort(arr, arr+n);
}

void solution(){
    int left=0, right=n-1;

    if(arr[0]>0)
    {
        liq1=0;
        liq2=1;
    }
    else if(arr[n-1]<0)
    {
        liq1=n-2;
        liq2=n-1;
    }
    else
    {
        while(left<right)
        {
            if(abs(arr[left]+arr[right])<answer)
            {
                liq1=left;
                liq2=right;
                answer=abs(arr[left]+arr[right]);
            }

            if(arr[left]+arr[right] < 0)
                left++;
            else if(arr[left]+arr[right]>0)
                right--;
            else
            {
                liq1=left;
                liq2=right;
                break;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<arr[liq1]<<" "<<arr[liq2];

    return 0;
}