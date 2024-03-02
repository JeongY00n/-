#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int H,W,N,M;
    cin>>H>>W>>N>>M;

    int h=H/(N+1),w=W/(M+1);
    if(H%(N+1))
        h++;
    
    if(W%(M+1))
        w++;

    cout<<h*w;

    // cout<<ceil(H/(N+1)*ceil(W/M+1));
    return 0;
}