#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int check[11];
int n,maxi=0;
vector<int> sumsum;
vector<int> answer;
// 조합으로 이뤄진 주사위들로 만들 수 있는 합 계산
void findSum(int sum, vector<int> v, int cnt, vector<vector<int>> dice)
{
    if(cnt==n/2)
    {
        sumsum.push_back(sum);
        return;
    }
        
        
    for(int i = 0; i<6; i++)
    {
        findSum(sum+dice[v[cnt]-1][i],v,cnt+1,dice);
    }

}
// A의 값이 더 큰 경우를 카운팅
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
// A와 B의 주사위 조합으로 A가 이길 확률이 높은 경우를 answer에 저장
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
    findSum(0,A,0,dice);
    vector<int> sumA = sumsum;

    sumsum.clear();
    findSum(0,B,0,dice);
    vector<int> sumB=sumsum;

    sort(sumA.begin(),sumA.end());
    sort(sumB.begin(),sumB.end());
    int result = calc(sumA, sumB);

    if(maxi<result)
    {
        maxi = result;
        answer.clear();
        answer=A;
    }
    
}

void Combine(int idx, int cnt,vector<vector<int>> dice)
{
    if(cnt==n/2)
    {
        checkAB(dice);
        return;
    }
    
    for(int i = idx; i<=n; i++)
    {
        check[i]=1;
        Combine(i+1, cnt+1, dice);
        check[i]=0;
    }
}
vector<int> solution(vector<vector<int>> dice) {
    
    n = dice.size();
    Combine(1,0,dice);
    
    return answer;
}