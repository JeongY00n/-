#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    각 사원들의 근무 태도와 동료 평가 점수 비교
*/


int solution(vector<vector<int>> scores) {
    int answer = -1;
    vector<pair<int, int>> v;
    
    for(int i = 0; i<scores.size(); i++)
        v.push_back({scores[i][0], scores[i][1]});
    
    // 근무 태도 점수에 대해 내림차순 정렬
    sort(v.begin(), v.end(),greater<>());
    
    // 어떤 사원이 다른 임의의 사원보다 두 점수가 모두 낮은 경우 확인
    for(int i = 0; i<v.size(); i++){
        bool del=0;
        for(int j = 0; j<i; j++)
        {
            if(v[i].first<v[j].first && v[i].second<v[j].second)
            {
                v.erase(v.begin()+i); //해당 인덱스 위치의 값 제거
                del=1;
                break;
            }
        }
        if(del) i--;
            
    }
    
    // 총합에 대한 벡터 생성
    vector<pair<int, pair<int, int>>> sumOrder;
    for(int i = 0; i<v.size(); i++)
    {
        // cout<<v[i].first<<","<<v[i].second<<"\n";
        sumOrder.push_back({v[i].first+v[i].second,{v[i].first, v[i].second}});
        
    }
    
    // 총합에 대해 내림차순 정렬
    sort(sumOrder.begin(), sumOrder.end(),greater<>());
                            
                            
    int rank=1, temp=0;
    int flag=0, wan=scores[0][0]+scores[0][1];
    for(int i = 0; i<sumOrder.size(); i++){
        if(wan>sumOrder[i].first)break;
        else if(wan==sumOrder[i].first)
        {
            if(sumOrder[i].second.first==scores[0][0]
              && sumOrder[i].second.second==scores[0][1])
                flag=1;
            temp++;
        } 
            
        rank++;
    }
    if(flag) answer=rank-temp;
    return answer;
}