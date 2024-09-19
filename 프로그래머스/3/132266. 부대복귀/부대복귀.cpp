#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> node[100001];
    for(int i = 0; i<roads.size(); i++)
    {
        node[roads[i][0]].push_back(roads[i][1]);
        node[roads[i][1]].push_back(roads[i][0]);
    }
    
    queue<pair<int,int>> q;
    q.push({destination,0});
    
    int visited[100001]={0};
    fill(visited,visited+n+1,-1);
    visited[destination]=0;
    
    while(!q.empty()){
        pair<int,int> now = q.front(); q.pop();
        int from=now.first, time=now.second;

        for(int i = 0; i<node[from].size(); i++){
            if(visited[node[from][i]]!=-1&&visited[node[from][i]]<=time+1)continue;
            visited[node[from][i]]=time+1;
            
            q.push({node[from][i],time+1});
        }
    }
    
    
    for(int i = 0; i<sources.size(); i++)
        answer.push_back(visited[sources[i]]);
    
    
    return answer;
}