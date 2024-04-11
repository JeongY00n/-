#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int idx;
bool cmp(string a, string b){
    int size=min(a.size(),b.size());
    
    if(a[idx]==b[idx]){
        return a<b;
    }
    
    return a[idx]<b[idx];
    
    
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx=n;
    sort(strings.begin(), strings.end(), cmp);
    
    for(int i = 0; i<strings.size(); i++)
        answer.push_back(strings[i]);
    
    return answer;
}