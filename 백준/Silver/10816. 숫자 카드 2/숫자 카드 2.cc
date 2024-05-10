#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int num1[500000], num2[500000];
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>num1[i];

    cin>>m;
    for(int i = 0; i<m; i++)
        cin>>num2[i];
        
    sort(num1, num1+n);
}
// 찾고자하는 숫자를 초과하는 값이 등장하는 위치
int upper_bound(int num){
    int left=0,right=n-1;

    while(left<=right){
        int mid=(left+right)/2;

        if(num1[mid]>num)
            right=mid-1;
        else
            left=mid+1;
    }

    return left;

}
// 찾고자하는 숫자 이상의 값이 시작하는 위치
int lower_bound(int num){
    int left=0,right=n-1;

    while(left<=right){
        int mid = (left+right)/2;

        if(num1[mid]>=num)
            right=mid-1;
        else
            left=mid+1;
    }

    return left;
} 
void solution(){
    for(int i = 0; i<m; i++)
        cout<<upper_bound(num2[i])-lower_bound(num2[i])<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    
    return 0;
}