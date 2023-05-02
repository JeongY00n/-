#include<iostream>

using namespace std;

double num, east, west, south, north;
int visited[30][30];
double answer;

void init(){
    cin>>num>>east>>west>>south>>north;
    east/=100;
    west/=100;
    south/=100;
    north/=100;
}

void solution(int cnt, int y, int x, double percent){
    if(visited[y][x]>=2 || percent == 0)
    {
        return;
    }
    if(cnt == num)
    {
        answer+=percent;
        return;
    }
    //East
    
    visited[y][x+1]++;
    solution(cnt+1, y, x+1, percent*east);
    visited[y][x+1]--;
    
    //West

    visited[y][x-1]++;
    solution(cnt+1, y, x-1, percent*west);
    visited[y][x-1]--;
    
    //South
    
    visited[y+1][x]++;
    solution(cnt+1, y+1, x, percent*south);
    visited[y+1][x]--;
    
    //North
    
    visited[y-1][x]++;
    solution(cnt+1, y-1, x, percent*north);
    visited[y-1][x]--;
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    visited[15][15]=1;
    solution(0, 15, 15, 1);
    cout.precision(30);

    if(answer == 1)
        cout<<"1.0";
    else
        cout<<answer;
    return 0;
}