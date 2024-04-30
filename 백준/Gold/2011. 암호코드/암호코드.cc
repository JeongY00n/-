#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string code; cin>>code;
    int len=code.size();

    // [두자리 숫자로 암호화된 문자인지 한자리 숫자로 암호화된 문자인지][자릿수]
    int dp[2][5000]={};
    
    // 앞의 두자리에 대해서는 따로 값을 세팅해줌
    for(int i = 0; i<2; i++)
    {
        if(1<=(code[i]-'0')&&(code[i]-'0')<=9)
            dp[0][i]=1;
        if(i==1&&10<=(code[i-1]-'0')*10+(code[i]-'0')&&(code[i-1]-'0')*10+(code[i]-'0')<=26)
            dp[1][i]=1;
    }
    // 맨 앞의 숫자가 0이 아닌 경우에 대해서만
    if(dp[0][0])
    {
        for(int i = 2; i<len; i++)
        {
            if(1<=(code[i]-'0')&&(code[i]-'0')<=9)
            {
                dp[0][i]=(dp[0][i-1]+dp[1][i-1])%1000000;
                //cout<<code[i]-'0';
            }
            if(10<=(code[i-1]-'0')*10+(code[i]-'0')&&(code[i-1]-'0')*10+(code[i]-'0')<=26)
                dp[1][i]=(dp[0][i-2]+dp[1][i-2])%1000000;
        }
    }
    cout<<(dp[0][len-1]+dp[1][len-1])%1000000;

    return 0;
}