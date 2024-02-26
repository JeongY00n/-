#include <string>
#include <vector>
#include<iostream>
using namespace std;

/*
    최대 라운드 수
    버리지 않고 누적해두다가 합이 n+1인 두장의 카드를 내야할 때 코인에서 -1을 해주고
    만약 더이상 낼 코인이 없다면 게임 종료
*/

vector<pair<int,int>> having;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    
    for(int i=0;i<n/3; i++)
        having.push_back({cards[i], 0});
    
    int idx=n/3;
    
    while(idx+2<=n)
    {
        for(int i = idx; i<idx+2; i++)
            having.push_back({cards[i],1});
        idx+=2;
        
        int flag=0;
        for(int i = 0; i<having.size(); i++)
        {
            if(having[i].second==-1)continue; // 이전에 이미 사용한 카드
            for(int j = i+1; j<having.size(); j++)
            {
                if(having[j].second==-1)continue; // 이전에 이미 사용한 카드
                if(having[i].first+having[j].first==n+1) // 두 카드의 합이 n+1인 경우
                {
                    if(coin - having[i].second - having[j].second >=0) // 동전 소모 가능한 경우
                    {
                        coin = coin - having[i].second - having[j].second;
                        having[i].second=-1;
                        having[j].second=-1;
                        flag=1;
                        break; 
                    }
                }
            }
            if(flag)break;
        }
        
        if(!flag) // 카드를 낼 수 없는 경우 게임 종료
            break;
        answer++;
        cout<<answer<<" ";
    }
    
    
    
    return answer;
}