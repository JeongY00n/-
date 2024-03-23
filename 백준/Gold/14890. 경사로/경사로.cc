#include<iostream>

using namespace std;

#define MAX 100

/*
    경사로 높이 1, 길이 L
    지도에서 상->하, 좌->우 모서리 확인
    이동하려는 다음 칸의 높이가 낮은 경우 넘어감
    높이가 같다면 진행방향으로 계속 나아감
    만약 1크기만큼 높은 칸이 주어졌다면 높은 칸 위치에서 L만큼의 뒤를 확인한 후 경사로를 설치할 수 있다면 설치

*/
int N, L;
int map1[MAX][MAX], map2[MAX][MAX];
void init(){
    cin>>N>>L;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
        {
            cin>>map1[i][j];
            map2[j][i]=map1[i][j];
        }
}

int solution(int map[][MAX]){
    int answer=0;
    for(int x = 0; x<N; x++)
    {
        int check[100]={0};
        int flag=0;
        for(int y = 0; y<N-1; y++)
        {
            // 다음 칸과 높이 차이가 1 초과인 경우 
            if(abs(map[y+1][x]-map[y][x])>1)
            {
                flag=1;
                break;
            }

            // 다음 칸이 1만큼 높은 경우
            else if(map[y+1][x]-map[y][x]==1)
            {
                int back = y+1-L;
                // 지도를 벗어나는 경우
                if(back<0)
                {
                    flag=1;
                    break;
                }
 
                for(int k = back; k<=y; k++)
                {
                   // 경사로로 이어진 칸의 높이 차가 1 이상인 경우, 이미 경사로가 설치된 경우
                    if(map[y+1][x]-map[k][x]!=1 || check[k])
                    {
                        flag=1;
                        break;
                    }
                    check[k]++;
                }
            }
            // 다음 칸이 1만큼 낮은 경우
            else if(map[y+1][x]-map[y][x]==-1)
            {
                int back = y+L;
                // 지도를 벗어나는 경우
                if(back>=N)
                {
                    flag=1;
                    break;
                }

                for(int k = y+1; k<=back; k++)
                {
                   // 경사로 연결된 칸의 높이 차가 1 이상인 경우, 이미 경사로가 설치된 경우
                    if(map[k][x]-map[y][x]!=-1 || check[k])
                    {
                        flag=1;
                        break;
                    }
                    check[k]++;
                }
            }
        }
        if(!flag)
            answer++;
        
        
    }

    return answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int A = solution(map1);
    int B = solution(map2);
    cout<<A+B;

    return 0;
}