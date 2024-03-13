#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/*
    우선순위 큐를 사용하여 양을 더 우선하고, 늑대가 등장하면 부모를 더 우선으로 두고 같은 레벨에서는 정렬하여 진행
    왼쪽 갔다가 오른쪽 가는 경우와
    오른쪽 갔다가 왼쪽가는 경우가 존재
    왼쪽만 가는 경우
    오른쪽만 가는 경우
*/
struct INFO{
    int id, level, s, w;
    
    bool operator<(const INFO&other)const{
        if(w>other.w)return false;
        if(w<other.w)return true;
        if(level>other.level)return false;
        if(level<other.level)return true;
        if(s<other.s)return false;
        if(s>other.s)return true;
        
        
        
        
        
        return false;
    }
};

void Find(){
    
    
}
vector<int> v[17];
priority_queue<INFO> pq;
void Find(vector<int> info){
    pq.push({0, 0, 0});
    
    int sheep=0, wolf=0;
    
    while(!pq.empty()){
        INFO now = pq.top(); pq.pop();
        
        int id = now.id;
        int level = now.level;
        int s = now.s;
        int w = now.w;
        
        if(info[id]==0)sheep++;
        else if(info[id]==1)wolf++;
        cout<<id<<","<<sheep<<","<<wolf<<"\n";
        for(int i = 0; i<v[id].size(); i++)
        {
            if(info[v[id][i]]==0)// 양인경우
            {
                pq.push({v[id][i], level+1, s+1, w});
                cout<<v[id][i]<<"\n";
            }
                
            else if(info[v[id][i]]==1) // 늑대인경우
            {
                if(sheep==wolf+1)continue;
                pq.push({v[id][i], level+1, s, w+1});
                cout<<v[id][i]<<"\n";
            }
                
        }
    }
    //cout<<sheep;
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(int i = 0; i<edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        
        v[a].push_back({b});
    }
    Find(info);
    return answer;
}