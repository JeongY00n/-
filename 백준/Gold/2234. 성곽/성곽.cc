#include<iostream>
#include<bitset>
#include<string>
#include<queue>
using namespace std;

/*

bitset<출력길이>(변수)

1 2 4 8
좌 상 우 하
좌상

0000

    visited에 몇번째방인지 check
    해당방의 칸 카운팅

    1. 이 성에 있는 방의 개수
    2. 가장 넓은 방의 넓이
    3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
*/
int n,m,map[50][50][4];
int visited[50][50], roomsize[2500];
int maxi;
void init(){
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            int num;
            cin>>num;
            string a = bitset<4>(num).to_string();
            // 5에대한 2진수
            // 0101를 
            // 1010으로 저장해야함
            map[i][j][3] = a[0]-'0';
            map[i][j][2] = a[1]-'0';
            map[i][j][1] = a[2]-'0';
            map[i][j][0] = a[3]-'0';
        }
    }
    
}
int fy[] = {0,-1,0,1};
int fx[] = {-1,0,1,0};
void solution(int number, int starty, int startx){
    queue<pair<int, int>> q;
    q.push({starty, startx});
    visited[starty][startx]=number;
    int cnt = 1;

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        int y = now.first;
        int x = now.second;
        
        for(int i = 0; i<4; i++)
        {
            int ny = y+fy[i];
            int nx = x+fx[i];

            if(map[y][x][i]==1)continue;
            if(ny<0||nx<0||ny>=m||nx>=n)continue;
            if(visited[ny][nx]!=0)continue;
            visited[ny][nx]=number;
            q.push({ny, nx});

            cnt++;
        }
    }

    maxi = max(maxi, cnt);
    roomsize[number]=cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int number = 0;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(visited[i][j]!=0)continue;
            number++;
            solution(number, i, j);
        }
    }

    int rn = 1;
    int maxisum = 0;
    for(int i = 0; i<m; i++)
    {
        rn = visited[i][0];
        for(int j = 0; j<n; j++)
        {   
            if(rn==visited[i][j])continue;
            maxisum = max(maxisum,roomsize[rn]+roomsize[visited[i][j]]);
            rn = visited[i][j];
        }
    }

    for(int j = 0; j<n; j++)
    {
        rn = visited[0][j];
        for(int i = 0; i<m; i++)
        {   
            if(rn==visited[i][j])continue;
            maxisum = max(maxisum,roomsize[rn]+roomsize[visited[i][j]]);
            rn = visited[i][j];
        }
    }

    cout<<number<<"\n";
    cout<<maxi<<"\n";
    cout<<maxisum<<"\n";
    return 0;
}