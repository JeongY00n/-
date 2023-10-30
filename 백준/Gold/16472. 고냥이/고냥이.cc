#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
    배열 생성해서 인식한 알파벳이 몇개인지 확인
    투포인터
    만약 인식할 수 있는 알파벳의 갯수를 초과하지 않았다면 right+1
    인식할 수 있는 알파벳의 갯수를 초과했다면 left+1
    문자열의 길이를 확인하며 answer값 갱신
*/
int n;
string str;
int check[26];

void init(){
    cin>>n;
    cin>>str;
}

void solution(){
    int left=0,right=0;
    int len=1, answer=1;
    int cnt=1;

    check[str[left]-'a']=1;

    while(left<=right)
    {
        if(right+1 >= str.size())break;

        if(check[str[right+1]-'a']==0)
        {
            // 인식할 수 있는 알파벳의 종류를 초과한 경우
            if(cnt+1>n)
            {
                // left 인덱스에 해당하는 알파벳 갯수에 -1
                check[str[left]-'a']--;
                // 만약 check 값이 0이면 인식한 알파벳 갯수에 -1
                if(check[str[left]-'a']==0)
                    cnt--;
                
                left++;
                len--;
            }
            else
            {
                right++;
                check[str[right]-'a']++;
                len++;
                cnt++;
            }
        }
        else
        {
            right++;
            check[str[right]-'a']++;
            len++;
        }

        answer = max(answer, len);
        
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