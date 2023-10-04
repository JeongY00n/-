#include<iostream>
#include<vector>
using namespace std;

/*
    완탐
    
*/
int n;
char map[6][6];
vector<pair<int, int>> teacher;
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            char a;
            cin>>a;
            if(a==' ')
                cin>>a;
            map[i][j]=a;
            if(a=='T')
            {
                teacher.push_back({i,j});
            }
        }    
    }
}
int fy[]={-1,1,0,0};
int fx[]={0,0,-1,1};
bool isOK(){
    for(int i = 0; i<teacher.size(); i++)
    {
        int y = teacher[i].first;
        int x = teacher[i].second;

        for(int j = 0; j<4; j++)
        {   
            int op=1;
            while(1){
                int ny = y+fy[j]*op;
                int nx = x+fx[j]*op;

                if(ny<0||nx<0||ny>=n||nx>=n)break;
                if(map[ny][nx]=='S')return false;
                if(map[ny][nx]=='O'||map[ny][nx]=='T')break;
                op++;
            }
        }
    }
    return true;
}

int endflag=0;
void solution(int idx, int cnt){
    if(idx==n*n&&cnt<3)return;
    if(cnt==3)
    {
        if(isOK()) endflag=1;
        return;
    }

    if(endflag)return;

    int y = idx/n;
    int x = idx%n;

    if(map[y][x]=='X'){
        map[y][x]='O';
        solution(idx+1, cnt+1);
        map[y][x]='X';

        solution(idx+1, cnt);
    }
    else
        solution(idx+1, cnt);

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution(0,0);
    
    if(endflag)cout<<"YES";
    else cout<<"NO";
    return 0;
}