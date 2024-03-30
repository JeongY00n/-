#include<iostream>
#include<cmath>
using namespace std;

/*
    twopointer로 1~4000000(N) 내의 소수들의 합을 계산
    sum < N 인 경우 right++
    sum > N 인 경우 left++
    sum == N 인 경우 cnt++
*/

int n;
int cnt = 0;
int num[4000001];

void isDecimal(){
    for(int i = 2; i<=n; i++)
        num[i]=i;
    for(int i = 2; i<=sqrt(n); i++)
    {
        if(num[i]==0)continue;
        for(int j = 2*i; j<=n; j+=i)
            num[j]=0;
    }
}


void solution(){
    int left = 2, right = 2, sum = 2;
    
    while(left<=right && right<=n){

        if(sum<n)
        {
            right++;
            while(num[right]==0)
                right++;
            sum+=num[right]; 
        }
        else if(sum>n)
        {
            sum-=num[left];
            left++;
            while(num[left]==0)
                left++;
        }
        else if(sum == n)
        {
            cnt++;
            right++;
            while(num[right]==0)
                right++;
            sum+=num[right];
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    isDecimal();
    solution();
    cout<<cnt;
    return 0;
}