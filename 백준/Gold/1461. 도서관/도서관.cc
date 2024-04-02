#include<iostream>
#include<algorithm>

using namespace std;

/*
    정렬
    왼쪽 끝부터 m개 만큼 좌표 방문
    m이 0이 되면 다시 0으로 돌아가 m 채우기
*/

int N,M;
int map[50], maxi;
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
    {
        cin>>map[i];
        maxi = max(maxi, abs(map[i]));   
    }
    sort(map, map+N);
}

void solution(){
    int answer=0;
    for(int i = 0; i<N; i+=M){
        if(map[i]>0)break;
        answer+=abs(map[i]*2);
    }

    for(int i = N-1; i>=0; i-=M){
        if(map[i]<0)break;
        answer+=abs(map[i]*2);
    }
    cout<<answer-maxi;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}