#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int check[11];
int n,maxi=0;
vector<int> sumsum;
vector<int> answer;
void sumOP(int sum, vector<int> v, int cnt, vector<vector<int>> dice)
{
    if(cnt==n/2)
    {
        sumsum.push_back(sum);
        return;
    }
        
        
    for(int i = 0; i<6; i++)
    {
        sumOP(sum+dice[v[cnt]-1][i],v,cnt+1,dice);
    }

}

int calc(vector<int> sumA, vector<int> sumB){
    int cnt=0;
    for(int i = 0; i<sumA.size(); i++)
    {
        for(int j = 0; j<sumB.size(); j++)
        {
            if(sumA[i]>sumB[j])
                cnt++;
            else
                break;
        }
    }
    
    return cnt;
}

void checkAB(vector<vector<int>> dice){
    
    vector<int> A,B;
    for(int i = 1; i<=n; i++)
    {
        if(check[i]==1)
            A.push_back(i);
        else
            B.push_back(i);
    }
    
    sumsum.clear();
    sumOP(0,A,0,dice);
    vector<int> sumA = sumsum;
    //cout<<A[0]<<","<<A[1]<<" "<<B[0]<<","<<B[1]<<"\n";
    // for(int i = 0; i<sumA.size(); i++)
    //     cout<<sumA[i]<<" ";
    // cout<<"\n";
    sumsum.clear();
    sumOP(0,B,0,dice);
    vector<int> sumB=sumsum;
    // for(int i = 0; i<sumA.size(); i++)
    //     cout<<sumB[i]<<" ";
    // cout<<"\n";
    sort(sumA.begin(),sumA.end());
    sort(sumB.begin(),sumB.end());
    int result = calc(sumA, sumB);
    // cout<<result<<"\n";
    if(maxi<result)
    {
        maxi = result;
        answer.clear();
        answer=A;
    }
    
}

void dfs(int idx, int cnt,vector<vector<int>> dice)
{
    if(cnt==n/2)
    {
        checkAB(dice);
        return;
    }
    
    for(int i = idx; i<=n; i++)
    {
        check[i]=1;
        dfs(i+1, cnt+1, dice);
        check[i]=0;
    }
}
vector<int> solution(vector<vector<int>> dice) {
    
    n = dice.size();
    dfs(1,0,dice);
    
    return answer;
}