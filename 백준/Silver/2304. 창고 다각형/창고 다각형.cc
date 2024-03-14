#include<iostream>
#include<algorithm>
using namespace std;

/*
    * 가장 왼쪽 오른쪽의 창고 높이는 기둥의 높이
    * 가장 높은 기둥 찾기
    * 가장 왼쪽 기둥에서 가장 높은 기둥으로 이동하면서 더 높은 값이 등장하면 비교값 갱신
    * 가장 오른쪽 기둥에서 가장 높은 기둥으로 이동하면서 더 높은 값이 등장하면 비교값 갱신
    * 현재 위치에서의 최대값이 창고 지붕의 높이
*/
int N, map[1001];
int start_x=2000,end_x=0;
int max_y=0,max_x;

void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
    {
        int x,y;
        cin>>x>>y;
        map[x]=y;
        start_x=min(start_x,x); end_x=max(end_x,x);

        // 가장 큰 y
        if(max_y<y)
        {
            max_y=y;
            max_x=x;
        }
    }
}

void solution(){
    int answer=0;
    
    // 시작 지점의 높이와 비교하여 더 큰 값을 temp로 갱신
    int temp = map[start_x];
    for(int i = start_x; i<=max_x; i++)
    {
        // temp보다 큰 경우 temp값 갱신
        if(temp<map[i])
            temp=map[i];
        
        answer+=temp;
    }

    // 종료 지점의 높이와 비교하여 더 큰 값을 temp로 갱신
    temp = map[end_x];
    for(int i = end_x; i>max_x; i--)
    {
        // temp보다 큰 경우 temp값 갱신
        if(temp<map[i])
            temp=map[i];
        
        answer+=temp;
    }

    cout<<answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}