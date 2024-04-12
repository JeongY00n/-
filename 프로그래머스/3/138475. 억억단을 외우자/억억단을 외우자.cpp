#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

/*
    s부터 e까지의 숫자들의 약수의 개수 구하기
    약수의 개수에 대해 오름차순 정렬
*/

struct INFO{
    int cnt, num;
    
    
};
bool cmp(INFO a, INFO b) {
    if(a.cnt==b.cnt)
        return a.num<b.num;
    return a.cnt>b.cnt;
}
vector<INFO> v;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    int cnt[5000001]={0};
    fill(cnt, cnt+e+1, 0);
    
    for(int i = 1; i<=e; i++)
    {
        for(int j = i; j<=e; j+=i)
        {
            cnt[j]++;
        }
            
    }
    for(int i = 1; i<=e; i++)
    {
        v.push_back({cnt[i],i});
    }
        
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i<starts.size(); i++){
        int s=starts[i];
        for(int j = 0; j<v.size(); j++){
            int n = v[j].num;
            
            if(s<=n)
            {
                answer.push_back(n);
                break;
            }
                
        }
    }
    
    
    return answer;
}