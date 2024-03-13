#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


vector<int> node[17];
int answer = 0;
void Find(vector<int> info, int id, queue<int> next_way, int sheep, int wolf){
    
    // 현재 위치에 있는 양 또는 늑대 확인
    if(info[id]==0)sheep++;
    else wolf++;
    
    // 만약 늑대와 양의 수가 동일해진다면 return
    if(sheep<=wolf)return;
    answer = max(answer, sheep);
    
    for(int i = 0; i<node[id].size(); i++)
        next_way.push(node[id][i]);
    
    for(int i = 0; i<next_way.size(); i++)
    {
        int next = next_way.front();
        next_way.pop();
        Find(info, next, next_way, sheep, wolf);
        next_way.push(next);
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {

    for(int i = 0; i<edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        
        node[a].push_back({b});
    }
    queue<int> way;
    Find(info,0,way,0,0);
    return answer;
}