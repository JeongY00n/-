#include<iostream>

using namespace std;

/*
      1 2 3 4 5 6 7
    0 0 1
    1 
    2

    이동 횟수와 자두의 위치, 시간에 대한 idx를 가진 삼차원배열 생성
    dp[]
*/

int T,W;
int tree_num[1001], dp[1001][32][3]={0}; // [초] [이동횟수] [위치] = 자두갯수
void init(){
    cin>>T>>W;

    for(int i = 1; i<=T; i++)
        cin>>tree_num[i];

}

void solution(){

    if(tree_num[1]==1)
        dp[1][0][1]=1;
    else
        dp[1][1][2]=1;
    
    int answer = 0;

    answer = max(dp[1][0][1], dp[1][1][2]);

    for(int t = 2; t<=T; t++)
    {
        for(int c = 0; c<=W; c++)
        {
            // t시간에 1번 나무에서 자두가 떨어짐
            // t-1시간에 대해 저장된 자두 갯수에 대해
            // 현재 1번 위치에 있는 경우와 2번 위치에서 이동을 해야하는 경우를 비교하여
            // 더 큰 값에 +1하여 배열에 저장
            if(tree_num[t]==1)
            {
                dp[t][c][1]=max(dp[t-1][c][1], dp[t-1][c-1][2])+1;
                dp[t][c][2]=max(dp[t-1][c-1][1], dp[t-1][c][2]);
            }

            // t시간에 2번 나무에서 자두가 떨어짐
            if(tree_num[t]==2)
            {
                dp[t][c][1]=max(dp[t-1][c][1], dp[t-1][c-1][2]);
                dp[t][c][2]=max(dp[t-1][c-1][1], dp[t-1][c][2])+1;
            }
            
            answer = max(answer, max(dp[t][c][1], dp[t][c][2]));
        }
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