#include<iostream>
#include<stack>
using namespace std;
/*

*/

int a, num[1000000];
int check[1000001], ngf[1000001];
void init(){
    cin>>a;
    for(int i = 0; i<a; i++)
    {
        cin>>num[i];
        check[num[i]]++;
    }
}

void solution(){
    stack<int> s;
    s.push(0);
    for(int i = 1; i<a; i++)
    {
        if(check[num[s.top()]]>=check[num[i]])
            s.push(i);
        else
        {
            while(check[num[s.top()]]<check[num[i]])
            {
                ngf[s.top()]=num[i];
                s.pop();
                if(s.empty())break;
            }
            s.push(i);
        }
    }
}

void print_answer(){
    for(int i = 0; i<a; i++)
    {
        if(ngf[i]==0)
            cout<<-1<<" ";
        else
            cout<<ngf[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    print_answer();

    return 0;
}