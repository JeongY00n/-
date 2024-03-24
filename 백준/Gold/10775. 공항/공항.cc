#include<iostream>

using namespace std;

/*
    최대한 뒤쪽 번호에 도킹해서 많은 비행기를 도킹시키도록 한다
*/
int G,P;
int check[100001],nextidx[100001];
int Find(int x){
    if(x==nextidx[x]) return x;
    return nextidx[x]=Find(nextidx[x]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a>b) nextidx[a]=b;
    else nextidx[b]=a;
}
bool find_Platform(int gate){
    for(int i = gate; i>=1; i--)
    {
        i = Find(nextidx[i-1]);
        if(check[i]==0)
        {
            check[i]=1;
            Union(i,i-1);
            return true;
        }
    }
    return false;
}
void init(){
    cin>>G>>P;
    for(int i = 1; i<=G; i++)
        nextidx[i]=i;
}
void solution(){
    int gate,answer=0,end_flag=0;
    for(int i = 0; i<P; i++)
    {
        cin>>gate;
        if(!end_flag&&find_Platform(gate))
            answer++;
        else
            end_flag=1;
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}