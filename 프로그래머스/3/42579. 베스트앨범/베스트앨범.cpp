#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second) // 고유번호 오름차순
        return a.first < b.first;
    return a.second>b.second; // 재생횟수 내림차순
}
bool cmp1(pair<string, int> a, pair<string, int> b){
    return a.second>b.second; // 장르의 재생횟수 내림차순
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, vector<pair<int, int>>> hash;
    unordered_map<string, int> cnt;
    
    for(int i = 0; i<genres.size(); i++)
    {
        hash[genres[i]].push_back({i,plays[i]});
        cnt[genres[i]]+=plays[i];
    }
    
    // 장르에 따른 고유번호와 재생 횟수에 대해 정렬
    for(auto &x:hash){
        sort(x.second.begin(), x.second.end(), cmp);
    }
    
    vector<pair<string, int>> v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), cmp1);
    
    for(const auto &x:v){
        for(int i = 0; i<hash[x.first].size(); i++)
        {
            if(i==2)break;
            answer.push_back(hash[x.first][i].first);
        }
    }
    return answer;
}