#include<iostream>

using namespace std;

int N,M;
int strong[5][5];
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin>>strong[i][j];
}

int visited[25]={0};
int answer;
void solution(int idx, int sum){
    if(idx==N*M){
        answer = max(answer, sum);
        return;
    }

    if(visited[idx]==1)
    {
        solution(idx+1, sum);
        return;
    }

    visited[idx]=1;
    int y = idx/M, x = idx%M;
    int mid = strong[y][x]*2;

    // 1번 모양
    int y1 = y+1, x1 = x;
    int y2 = y, x2 = x-1;
    if((y1>=0 && x1>=0 && y1<N && x1<M) && (y2>=0 && x2>=0 && y2<N && x2<M))
    {
        if(visited[y1*M+x1]==0 && visited[y2*M+x2]==0)
        {

            visited[y1*M+x1]=1;
            visited[y2*M+x2]=1;
            solution(idx+1, sum + mid + strong[y1][x1]+strong[y2][x2]);
            visited[y1*M+x1]=0;
            visited[y2*M+x2]=0;
        }
    }
    
    // 2번 모양
    y1 = y-1, x1 = x;
    y2 = y, x2 = x-1;
    if((y1>=0 && x1>=0 && y1<N && x1<M) && (y2>=0 && x2>=0 && y2<N && x2<M))
    {
        if(visited[y1*M+x1]==0 && visited[y2*M+x2]==0)
        {

            visited[y1*M+x1]=1;
            visited[y2*M+x2]=1;
            solution(idx+1, sum + mid + strong[y1][x1]+strong[y2][x2]);
            visited[y1*M+x1]=0;
            visited[y2*M+x2]=0;
        }
    }

    // 3번 모양
    y1 = y-1, x1 = x;
    y2 = y, x2 = x+1;
    if((y1>=0 && x1>=0 && y1<N && x1<M) && (y2>=0 && x2>=0 && y2<N && x2<M))
    {
        if(visited[y1*M+x1]==0 && visited[y2*M+x2]==0)
        {

            visited[y1*M+x1]=1;
            visited[y2*M+x2]=1;
            solution(idx+1, sum + mid + strong[y1][x1]+strong[y2][x2]);
            visited[y1*M+x1]=0;
            visited[y2*M+x2]=0;
        }
    }

    // 4번 모양
    y1 = y, x1 = x+1;
    y2 = y+1, x2 = x;
    if((y1>=0 && x1>=0 && y1<N && x1<M) && (y2>=0 && x2>=0 && y2<N && x2<M))
    {
        if(visited[y1*M+x1]==0 && visited[y2*M+x2]==0)
        {

            visited[y1*M+x1]=1;
            visited[y2*M+x2]=1;
            solution(idx+1, sum + mid + strong[y1][x1]+strong[y2][x2]);
            visited[y1*M+x1]=0;
            visited[y2*M+x2]=0;
        }
    }

    // 선택 X
    visited[idx]=0;
    solution(idx+1, sum);


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