#include<iostream>
#include<algorithm>
using namespace std;

/*
    회전연산 정보 입력받고 돌리기
*/

int n,m,k, map[51][51], cmap[51][51],original[51][51];
int rotate_info[6][3];
int answer=2e9;
void init(){
    cin>>n>>m>>k;
    for(int y=1; y<=n; y++)
        for(int x=1; x<=m; x++)
        {
            cin>>map[y][x];
            original[y][x]=map[y][x];
        }    

    for(int i = 0; i<k; i++)
        cin>>rotate_info[i][0]>>rotate_info[i][1]>>rotate_info[i][2];

    

}
void copy_map(){
    for(int y=1; y<=n; y++)
        for(int x=1; x<=m; x++)
            map[y][x]=original[y][x];
        
}
int order[6];
void rotation(int* order){

    for(int i = 0; i<k; i++){
        int r = rotate_info[order[i]][0];
        int c = rotate_info[order[i]][1]; 
        int s = rotate_info[order[i]][2];

        int start_y = r-s, start_x = c-s;
        int end_y = r+s, end_x = c+s;
        int y = start_y, x = start_x;
        int flag=1,cnt=0,op=1; // xy축방향, 방향전환수, +1or-1

        // 회전 연산하기 전에 cmap 갱신
        for(int y=1; y<=n; y++)
            for(int x=1; x<=m; x++)
                cmap[y][x]=map[y][x];

        while(1){
            if(flag==1)
            {   
                map[y][x+op] = cmap[y][x];
                x+=op;
            }
            else
            {
                map[y+op][x] = cmap[y][x];
                y+=op;
            }
            // 좌측상단
            if(y==start_y && x==start_x)
            {
                cnt++;
                flag=1;
                op=1;
            }
            // 우측상단
            else if(y==start_y && x==end_x)
            {
                cnt++;
                flag=0;
            }
            // 우측하단
            else if(y==end_y && x==end_x)
            {
                flag=1;
                op=-1;
                cnt++;
            }
            // 좌측하단
            else if(y==end_y && x==start_x)
            {
                cnt++;
                flag=0;
            }
            // 방향이 네 번 바뀌는 경우는 한 바퀴를 돌았다고 판단
            if(cnt==4)
            {
                start_x++;
                start_y++;
                end_x--;
                end_y--;
                cnt=0;
                y=start_y;
                x=start_x;
            }
            // 종료조건
            if((start_x>=end_x &&start_y>=end_y))
                break;
        }
        
        
    }

}

void Find_min(){
    for(int y = 1; y<=n; y++)
    {
        int sum=0;
        for(int x=1; x<=m; x++)
        {
            sum+=map[y][x];
        }
        answer = min(answer, sum);
    }
}

int visited[6];
void solution(int cnt){
    if(cnt==k)
    {
        // 회전연산 돌리기 전에 cmap 초기화
        copy_map();
        rotation(order);
        Find_min();
        return;
    }
    for(int i = 0; i<k; i++)
    {
        if(visited[i]==1)continue;
        visited[i]=1;
        // 순서 저장
        order[cnt]=i;
        solution(cnt+1);
        order[cnt]=0;
        visited[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution(0);
    cout<<answer;
    return 0;
}