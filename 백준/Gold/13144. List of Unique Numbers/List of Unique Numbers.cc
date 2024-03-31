#include<iostream>
using namespace std;

int N, num[100001];
void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
        cin>>num[i];
}

void solution(){
    long long left=0,right=0;
    int check[100001]={0};
    long long cnt=0;
    while(left<N){
        
        if(right==N||check[num[right]]==1)
        {
            cnt+=(right-left);

            check[num[left]]--;
            left++;
        }
        else if(check[num[right]]==0)
        {
            check[num[right]]++;
            right++;
        }
        //cout<<num[left]<<","<<num[right]<<"\n";
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    
    return 0;
}