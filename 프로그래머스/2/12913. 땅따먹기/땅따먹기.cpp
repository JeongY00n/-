#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[100000][4]={0};
    
    for(int i = 0; i<4; i++)
        dp[0][i]=land[0][i];
    
    for(int i = 1; i<land.size(); i++)
    {
        for(int j = 0; j<4; j++)
        {
            for(int t=0; t<4; t++)
            {
                if(j==t)continue;
                dp[i][j]=max(dp[i-1][t]+land[i][j], dp[i][j]);
            }
            answer=max(answer, dp[i][j]);
        }
    }
    
    
    return answer;
}