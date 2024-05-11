#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k,n; cin>>k>>n;
    long long num[10000]={0};
    long long left=1, right=1;
    for(int i = 0; i<k; i++)
    {
        cin>>num[i];
        right=max(right, num[i]);
    }
    
    long long answer=1;
    while(left<=right){
        long long mid = (left+right)/2;

        int cnt=0;

        for(int i = 0; i<k; i++)
        {
            cnt+=(num[i]/mid);
        }
        if(cnt>=n)
        {
            left=mid+1;
            answer=max(answer,mid);
        }
        else
            right=mid-1;
    }
    cout<<answer;

    return 0;
}