#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

/*
    P : 응시자
    O : 빈 테이블
    X : 파티션

*/

int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
int visited[5][5];
int flag=0;
void solution(vector<string> map, int y1, int x1, int y2, int x2)
{
    if(flag)return;
    if(abs(y1-y2)+abs(x1-x2)>2)
        return;
    else if(y1!=y2||x1!=x2)
    {
        if(map[y2][x2]=='P')
        {
            flag=1;
            return;
        }
            
    }
    
    for(int i = 0; i<4; i++)
    {
        int ny = y2+fy[i];
        int nx = x2+fx[i];

        if(ny<0||nx<0||ny>=5||nx>=5)continue;
        if(visited[ny][nx]==1)continue;
        if(map[ny][nx]=='X')continue;
        visited[ny][nx]=1;

        solution(map, y1,x1, ny,nx);

        visited[ny][nx]=0;
    }
    
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i<5; i++)
    {
        vector<pair<int, int>> yx;
        
        for(int j = 0; j<5; j++)
        {
            for(int p=0; p<5; p++)
            {
                if(places[i][j][p]=='P')
                    yx.push_back({j,p});
            }
        }
        if(yx.size()==0)
            answer.push_back(1);
        else
        {
            // 초기화
            memset(visited,0,sizeof(visited));
            flag=0;
            for(int p=0; p<yx.size(); p++)
            {
                // 시작 좌표 초기세팅
                visited[yx[p].first][yx[p].second]=1;
                
                solution(places[i], yx[p].first, yx[p].second, yx[p].first, yx[p].second);
                if(flag)break;
                
                // memset(visited,0,sizeof(visited));
                // visited[yx[p].first][yx[p].second]=1;
            }
            if(flag)
                answer.push_back(0);
            else
                answer.push_back(1);
        }
        
    }
    
    return answer;
}