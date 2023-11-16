#include<iostream>

using namespace std;

/*
    LCS : Longest Common Subsequence
*/

string a, b;
int dp[1001][1001]={0};
void init(){
    cin>>a>>b;
}

void solution(){
    int asize = a.size();
    int bsize = b.size();

    for(int i = 1; i<=asize; i++)
    {
        for(int j = 1; j<=bsize; j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<<dp[asize][bsize];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();


    return 0;
}