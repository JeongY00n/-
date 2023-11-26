#include<iostream>

using namespace std;

/*
    가장 왼쪽부터 시작해서 계란을 손에 들고 멀쩡한 계란을 친다
    * 손에 든 계란이 깨진 경우 넘어감 (손에 든 계란이 깨질때까지 계속)
    * 깰 계란이 없으면 넘어감
    * 내구도 - 무게
*/
int n, egg[8][2], crack[8], answer=0; 
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>egg[i][0]>>egg[i][1]; // 내구도, 무게
} 

int visited[8];
void solution(int now, int cnt){
    
    answer = max(answer, cnt);
    if(now==n)
    {
        return;
    }
    if(egg[now][0]<=0)
    {
        solution(now+1, cnt);
        return;
    }
    for(int idx=0; idx<n; idx++)
    {
        if(now==idx)continue;
        if(egg[idx][0]<=0)continue;

        egg[now][0]-=egg[idx][1];
        egg[idx][0]-=egg[now][1];


        if(egg[now][0]<=0 && egg[idx][0]<=0)
            solution(now+1, cnt+2);
        else if(egg[now][0]<=0)
            solution(now+1, cnt+1);
        else if(egg[idx][0]<=0)
            solution(now+1, cnt+1);
        else
            solution(now+1, cnt);


        egg[now][0]+=egg[idx][1];
        egg[idx][0]+=egg[now][1];

    }
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution(0,0);
    cout<<answer;

    return 0;
}