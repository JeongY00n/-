#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,X;
    int temp[250000]={0};
    cin>>N>>X;
    for(int i = 0; i<N; i++)
        cin>>temp[i];

    int answer=0, sum=0, cnt=0, idx=0;
    for(int i = 0; i<X; i++)
        sum+=temp[i];
    answer=sum; cnt++;
    for(int i = X; i<N;i++)
    {
        sum-=temp[idx];
        sum+=temp[i];
        if(answer<sum)
        {
            cnt=1;
            answer=sum;
        }
        else if(answer==sum)
            cnt++;
        
        idx++;
    }
    if(answer==0)
        cout<<"SAD";
    else
        cout<<answer<<"\n"<<cnt;
    
    return 0;
}