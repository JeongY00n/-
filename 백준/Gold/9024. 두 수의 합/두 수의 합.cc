#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int n;
long long k;
long long num[1000000];

void init(){
    memset(num,0,sizeof(num));
    cin>>n>>k;
    for(int i = 0; i<n; i++)
        cin>>num[i];
    sort(num, num+n);
}

void solution(){
    int left=0, right=n-1;
    int mini=2e9, cnt=0;
    while(left<right){
        long long temp=num[left]+num[right];

        if(temp==k)
        {
            right--;
            left++;
        }
        else if(temp<k)
            left++;
        else
            right--;

        // mini보다 더 작은 경우 
        // cnt=1, mini값 갱신
        if(abs(temp-k)<mini)
        {
            mini = abs(temp-k);
            cnt=1;
        }
        else if(abs(temp-k)==mini)
            cnt++;
    }
    cout<<cnt<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;

    for(int tc=1; tc<=T; tc++)
    {
        init();
        solution();
    }

    return 0;
}