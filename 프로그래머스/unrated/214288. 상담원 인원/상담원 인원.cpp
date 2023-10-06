#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    각 유형에대해 상담사 배정
*/

struct PARTICIPATE{
    int enter, need, endtime;
};

vector<PARTICIPATE> v[6];
int consult[6], answer=2e9;
int consulting[20];
int find_mintime(int k){
    int time = 0;
    
    for(int i = 1; i<=k; i++)
    {
        
        // 상담사의 수가 적은 경우
        if(consult[i]<v[i].size())
        {
            for(int j = 0; j<consult[i]; j++)
                consulting[j]=v[i][j].endtime; 
            
            int j = -1;
            int wconsult = consult[i];
            
            while(j+wconsult<v[i].size()-1){
                j++;
                int mini=0;
                
                // 본인보다 먼저 상담받고 있는 참가자에 대해서
                // 가장 빨리 끝나는 시간 확인
                for(int idx = 0; idx<consult[i]; idx++)
                {
                    if(consulting[mini]>consulting[idx])
                        mini = idx;   
                }
                // 상담을 신청했을 때 상담 없는 상담사가 있는 경우
                if(consulting[mini]<=v[i][wconsult+j].enter)
                {
                    // 새롭게 시작된 상담에 대해 끝나는 시간 갱신
                    consulting[mini]=v[i][wconsult+j].endtime;
                    continue;
                }
                //cout<<i<<"\n"<<wconsult+j<<" "<<consulting[mini]<<","<<v[i][wconsult+j].enter<<"\n";
                
                // 대기시간 추가
                time+=(consulting[mini]-v[i][wconsult+j].enter);
                //cout<<time<<" "<<(consulting[mini]-v[i][wconsult+j].enter)<<"\n";
                
                if(time>=answer) return 1e9;
                
                // 새롭게 시작된 상담에 대해 끝나는 시간 갱신
                consulting[mini]=v[i][wconsult+j].endtime + consulting[mini]-v[i][wconsult+j].enter;

            }
            
        }
    }
    
    return time;
}
void Combination(int idx, int k, int n){
    if(0==n)
    {
        int time = find_mintime(k);
        answer = min(answer, time);
        return;
    }
    
    for(int i = idx; i<=k; i++)
    {
        consult[i]++;
        Combination(i, k, n-1);
        consult[i]--;
    }
    
    
}
int solution(int k, int n, vector<vector<int>> reqs) {
    
    for(int i = 0; i<reqs.size(); i++)
        v[reqs[i][2]].push_back({reqs[i][0], reqs[i][1], reqs[i][0] + reqs[i][1]});
    
    
    // 일단 한 명씩 배치
    for(int i = 1; i<=k; i++)
        consult[i]=1;
    
    Combination(0, k, n-k);
    
    return answer;
}