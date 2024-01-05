#include<iostream>
#include<algorithm>

using namespace std;

/*
    모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제
    string answer[1001][1001];을 사용하면 저장하는 과정에서 그 이전 string 자체를 복사해오고 뒤에 하나를 덧 붙이는 식으로 짜여지므로
    시간이  O(n^3)의 시간복잡도를 가지게 된다.
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    string str1="", str2="";
    cin>>str1;
    cin>>str2;

    str1 = "0" + str1;
    str2 = "0" + str2;

    //dp
    int dp[1001][1001]={0};
    for(int i = 1; i<str2.size(); i++)
    {
        for(int j = 1; j<str1.size(); j++)
        {
            if(str1[j]==str2[i])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string LCS="";
    int start = str1.size()-1;
    for(int i = str2.size()-1; i>=1; i--)
    {
        for(int j = start; j>=1; j--)
        {
            if(dp[i][j]>dp[i][j-1] && dp[i][j]>dp[i-1][j])
            {
                start = j-1;
                LCS+=str1[j];
                break;
            }
            if(dp[i][j]==dp[i-1][j]) break;
        }
    }
    reverse(LCS.begin(), LCS.end());

    cout<<dp[str2.size()-1][str1.size()-1]<<"\n"<<LCS;
    
    return 0;
}