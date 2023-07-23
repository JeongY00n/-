#include<iostream>

using namespace std;
/*
벨트가 각 칸 위에 있는 로봇과 한 칸 이동
벨트 이동 방향으로 로봇이 한 칸 움직임
벨트 직접 하나씩 옮기면 시간이 많이 듦 =>  up, down 위치를 변경해줌
*/

int n, k, belt[201];
int up,down,answer=1;
int robot[201];
int zero[201];

void init(){
    cin>>n>>k;
    for(int i = 1; i<=2*n; i++)
        cin>>belt[i];
    up=1;down=n;
}

int cnt = 0;
void moving(){
    if(robot[down]==1)robot[down]=0;
    int idx=down;
    
    while(idx!=up)
    {
        int next = idx;
        idx--;
        if(idx==0) idx=2*n;


        // 현재 위치에 로봇이 존재하고
        // 다음 위치에는 로봇이 없으며
        // 다음 위치의 내구도가 1 이상인 조건을 만족
        if(robot[idx]==1 && robot[next]==0 && belt[next]>=1)
        {
            robot[idx]=0;
            robot[next]=1;
            belt[next]--;
            if(belt[next]==0 && zero[next]==0)
            {
                zero[next]=1;
                cnt++;
            }
        } 
    }

    if(robot[down]==1)robot[down]=0;
}

void solution(){
    int flag=0;
    while(cnt<k)
    {
        up--;down--;
        if(up==0)
            up=2*n;
        if(down==0)
            down=2*n;

        if(flag==1)// 한 칸 앞으로 이동하는 절차
            moving();
        
        // 올리는 위치
        if(belt[up]>0)
        {
            flag=1;
            robot[up]=1;
            belt[up]--;
            if(belt[up]==0 && zero[up]==0)
            {
                zero[up]=1;
                cnt++;
            }

        }

        if(cnt>=k) return;
        answer++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<answer;
    return 0;
}