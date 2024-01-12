#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    string bomb;
    cin>>str;
    cin>>bomb;

    int len=str.size(), blen=bomb.size();
    string answer = "";

    for(int i = 0; i<len; i++)
    {
        answer+=str[i];
        
        if(answer.size()>=blen) // 폭발 문자열의 길이보다 크거나 같은 경우
        {
            int flag=0; // 동일여부 판단
            // 슬라이딩윈도우, 폭발 문자열이 존재하는지 확인
            for(int j = 0; j<blen; j++)
            {
                if(answer[answer.size()-blen+j] != bomb[j]) // 동일하지 않은 경우
                {
                    flag=1;
                    break;
                }
            }
            if(!flag) // 동일한 경우 폭발
                answer.erase(answer.end()-blen, answer.end());
        }
    }
   

    if(answer=="")
        cout<<"FRULA";
    else
        cout<<answer;
    return 0;
}