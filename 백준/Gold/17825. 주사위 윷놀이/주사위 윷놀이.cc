#include<iostream>
#include<vector>
using namespace std;

/*
    맵을 만들기
    10, 20, 30에 대해서 경로 따로 설정해주기
*/
struct NODE{
    int to;
    int flag;
};
int arr[50], score[50], turn[30];
void makemap(){
    // map 이동 경로 저장
    for(int i = 0; i<21; i++)
        arr[i]=i+1;
    arr[21]=21;
    for(int i = 22; i<27; i++)
        arr[i]=i+1;
    arr[27] = 20; arr[28] = 29; arr[29] = 30;
    arr[30] = 25; arr[31] = 32; arr[32] = 25;

    // 방향 전환
    turn[5] = 22; turn[10] = 31; turn[15] = 28;

    // 각 위치의 점수 저장
    for (int i = 0; i < 21; i++) 
        score[i] = 2 * i;
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[25] = 25; score[26] = 30; score[27] = 35;
    score[28] = 28; score[29] = 27; score[30] = 26;
    score[31] = 22; score[32] = 24;
}

int dice[10]; // 주사위에서 나올 수 있는 수 10개 순서대로
int horse[5]; // 말의 위치
int check[30];
int answer=0;


void solution(int cnt, int sum)
{
    if(cnt==10)
    {
        answer=max(answer, sum);
        return;
    }
    
    for(int i = 0; i<4; i++)
    {
        
        int prev = horse[i];
        int cur = prev;
        int move = dice[cnt];
        
        // 방향을 전환해야하는 경우 방향 전환하면서 한 칸 이동
        if(turn[prev]>0)
        {
            cur=turn[prev];
            move--;
        }
        while(move>0)
        {
            cur=arr[cur];
            move--;
        }
        
        // 도착위치지 아닌데, 다른 말이 있는 경우
        if(cur!=21 && check[cur]) continue;

        // 이전 위치는 0으로 초기화, 이동할 위치는 1로 표시
        check[prev]=0;
        check[cur]=1;
        horse[i]=cur;

        solution(cnt+1, sum+score[cur]);

        check[prev]=1;
        check[cur]=0;
        horse[i]=prev;
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i<10; i++)
        cin>>dice[i];

    makemap();
    solution(0,0);
    
    cout<<answer;

    return 0;
}