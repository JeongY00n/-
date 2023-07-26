#include<iostream>
#include<algorithm>
using namespace std;

/*
요리도하고
diy
양모펠트
보석 십자수
그림그리기
CD 듣기
가챠구매
책읽기
허영심은 어디서온다고..?
*/

/*
dp
모든 경우의 수를 확인해야함
100,000 ^ 3 = 100,000,000,000,000,000 오래걸림
각 위치에서 얻을 수 있는 최대값과 최소값을 저장해서 가지치기하기
*/

int n, answer_mini=2e9, answer_maxi;
int map[100000][3], maxi[3], mini[3];
int now_maxi[3], now_mini[3];

void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<3; j++)
                cin>>map[i][j];
        
    }
    // memset(string.h) 대신 fill(algorithm)을 사용해야 2e9로 배열을 채울 수 있음
    fill(mini, mini+3, 2e9);
    
    
    for(int i = 0; i<3; i++)
    {
        maxi[i]=map[0][i];
        mini[i]=map[0][i];
    }

}

int fx[]={-1,0,1};
void solution(){

    for(int y = 1; y<n; y++)
    {
        fill(now_mini, now_mini+3, 2e9);
        for(int x = 0; x<3; x++)
        {
            for(int i = 0; i<3; i++)
            {
                int nx = x + fx[i];
                if(nx<0||nx>=3)continue;

                if(now_maxi[nx] < maxi[x]+map[y][nx])
                {
                    now_maxi[nx] = maxi[x]+map[y][nx];
                }
                if(now_mini[nx] > mini[x]+map[y][nx])
                {
                    now_mini[nx] = mini[x]+map[y][nx];
                    //cout<<now_mini[nx]<<"mini\n";
                }
            }
        }
        for(int x = 0; x<3; x++)
        {
            maxi[x]=now_maxi[x];
            mini[x]=now_mini[x];
        }
        
    }
    for(int x = 0; x<3; x++)
    {
        answer_maxi=max(answer_maxi, maxi[x]);
        answer_mini=min(answer_mini, mini[x]);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<answer_maxi<<" "<<answer_mini;
    return 0;
}