#include<iostream>
#include<string>
#include<vector>
using namespace std;

int S[21];
void add(int x){
    S[x]=1;
}
void remove(int x){
    S[x]=0;
}
void check(int x){
    if(S[x])
        cout<<"1\n";
    else
        cout<<"0\n";
}
void toggle(int x){
    if(S[x])
        S[x]=0;
    else
        S[x]=1;
}
void all(){
    for(int i = 1; i<=20; i++)
        S[i]=1;
}
void empty(){
    for(int i = 1; i<=20; i++)
        S[i]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M; cin>>M;
    for(int i = 0; i<M; i++)
    {
        string op;
        cin>>op;
        
        if(op=="add")
        {
            int num;
            cin>>num;
            add(num);
        }
        else if(op=="remove")
        {
            int num;
            cin>>num;
            remove(num);
        }
        else if(op=="check")
        {
            int num;
            cin>>num;
            check(num);
        }
        else if(op=="toggle")
        {
            int num;
            cin>>num;
            toggle(num);
        }
        else if(op=="all")
        {
            all();
        }
        else if(op=="empty")
        {
            empty();
        }

    }
    return 0;
}