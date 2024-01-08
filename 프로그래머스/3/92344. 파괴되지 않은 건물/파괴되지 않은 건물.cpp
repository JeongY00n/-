#include<iostream>
#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int map[1001][1001]={0};
    int answer=0;
    int n,m;
    
    n = board.size();
    m = board[0].size();
    
    for(int i = 0; i<skill.size(); i++)
    {
        int y1=skill[i][1], x1=skill[i][2];
        int y2=skill[i][3], x2=skill[i][4];
        int cost=skill[i][5];
        
        // 적군
        if(skill[i][0]==1) cost*=-1;
            
        map[y1][x1]+=cost; map[y2+1][x2+1]+=cost;
        map[y2+1][x1]+=cost*-1; map[y1][x2+1]+=cost*-1;
    }
    
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(j==0)continue;
            map[i][j]+=map[i][j-1];
        }
    }
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(j==0)continue;
            map[j][i]+=map[j-1][i];
        }
    }
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            board[i][j]+=map[i][j];
            if(board[i][j]>0) answer++;
        }  
    }
        
    
    return answer;
}