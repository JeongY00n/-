#include<iostream>
#include<algorithm>
using namespace std;
/*
    최대를 최소로 
    이분탐색
*/
int n,m,l, maxi;
vector<int> rest;
void init(){
    cin>>n>>m>>l;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin>>a;
        rest.push_back({a});
    }
    rest.push_back({0});
    rest.push_back({l});

    sort(rest.begin(), rest.end());
    
}

int answer = 2e9;
void solution(){
    int left = 1, right = l-1;

    while(left<=right)
    {
        int mid = (right+left)/2;
        int cnt = 0;
        for(int i = 0; i<n+1; i++)
            cnt+=(rest[i+1]-rest[i]-1)/mid ;
        

        if(cnt>m) left = mid+1;
        else 
        {
            right = mid-1;
            answer = min(answer,mid);
        }
        
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