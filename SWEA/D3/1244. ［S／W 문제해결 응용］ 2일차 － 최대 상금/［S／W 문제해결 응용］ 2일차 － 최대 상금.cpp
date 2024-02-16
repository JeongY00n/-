#include<iostream>
#include<string>
using namespace std;

string num;
int len, change, answer;

void init(){
    cin>>num;
    cin>>change;
    len=num.size();
    if(change>len)change=len;
    answer=0;
}

void Swap(int i, int j){
    char n = num[i];
    num[i]=num[j];
    num[j]=n;
}

void Combi(int start, int n){
    if(n==change)
    {
        int temp=stoi(num);
        if(answer<temp) answer=temp;
        return;
    }

    for(int i = start; i<len-1; i++)
    {
        for(int j = i+1; j<len; j++)
        {
            Swap(i,j);
            Combi(i, n+1);
            Swap(i,j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    
    for(int tc=1; tc<=T; tc++)
    {
        init();
        Combi(0,0);

        num=to_string(answer);
        
        cout<<"#"<<tc<<" "<<num<<"\n";
    }

    return 0;
}
