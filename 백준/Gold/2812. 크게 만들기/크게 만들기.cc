#include<iostream>
#include<stack>
using namespace std;

/*
    어차피 몇자리의 숫자인지는 정해지므로
    앞자리의 숫자가 최대한 클 수 있도록 하기
    
*/
int n,k;
char num[500001];
stack<char> answer, reanswer;
void init(){
    cin>>n>>k;
    cin>>num;
}

void solution(){
    int idx=0, erase=0;
    answer.push({num[idx]});
    while(idx<n-1){
        idx++;
        //cout<<answer.size()<<" ";
        if(answer.top()>=num[idx] && answer.size() < n-k)
        {
            answer.push({num[idx]});
        }
            
        else if(answer.top()<num[idx])
        {
            while(!answer.empty() && erase<k)
            {
                if(answer.top()>=num[idx])break;
                answer.pop();
                erase++;
            }
            answer.push({num[idx]});
        }
    }

    while(!answer.empty())
    {
        reanswer.push({answer.top()});
        answer.pop();
    }
    while(!reanswer.empty())
    {
        cout<<reanswer.top();
        reanswer.pop();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    
    return 0;
}