#include<iostream>
#include<algorithm>
using namespace std;

/*
    입력받는 드래곤 커브의 정보로 map에 좌표 지정을 해줌
    현재 좌표와 이전 좌표의 연결 방향에 따라서 a와 b값을 지정
    현재 좌표에 a,b를 더해주면서 좌표를 이어나감

    각 칸 하나하나
*/
int map[101][101];
vector<pair<int, int>> v;
int fy[]={0,-1,0,1};
int fx[]={1,0,-1,0};
void makepoint(){
    for(int i = 0; i<v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        map[y][x]=1;
    }
}
void dragon(int x, int y, int d, int g){

    // 0 세대
    v.clear();
    v.push_back({x,y});
    v.push_back({x+fx[d],y+fy[d]});
    
    // 드래곤 세대
    for(int i = 1; i<=g; i++)
    {
        
        int a=0, b=0;

        int size = v.size();
        // 이전 세대에서 가장 최근에 추가된 좌표 순서대로 다음 세대의 좌표를 이어나간다
        for(int j = size-1; j>0; j--)
        {
            // 가장 최근 좌표가 이전 좌표로부터 아래에 있는 경우
            // 새로운 좌표는 가장 최근 좌표의 오른쪽에 생성된다
            if(v[j].first-v[j-1].first==0 &&v[j].second-v[j-1].second>0)
            {
                a=1;b=0;
            }
            // 가장 최근 좌표가 이전 좌표로부터 왼쪽에 있는 경우
            // 새로운 좌표는 가장 최근 좌표의 아래에 생성된다
            else if(v[j].first-v[j-1].first<0&&v[j].second-v[j-1].second==0)
            {
                a=0;b=1;
            }
            // 가장 최근 좌표가 이전 좌표로부터 위에 있는 경우
            // 새로운 좌표는 가장 최근 좌표의 왼쪽에 생성된다
            else if(v[j].first-v[j-1].first==0&&v[j].second-v[j-1].second<0)
            {
                a=-1;b=0;
            }
            // 가장 최근 좌표가 이전 좌표로부터 오른쪽에 있는 경우
            // 새로운 좌표는 가장 최근 좌표의 왼쪽에 생성된다
            else if(v[j].first-v[j-1].first>0&&v[j].second-v[j-1].second==0)
            {
                a=0;b=-1;
            }
            
            int nx = v[v.size()-1].first+a;
            int ny = v[v.size()-1].second+b;
            v.push_back({nx,ny});
        }
    }

    makepoint();

}
void init(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        dragon(x,y,d,g);
    }
}
void findCnt(){
    int answer=0;
    for(int i = 0; i<101; i++)
    {
        for(int j = 0; j<101; j++)
        {
            if(map[i][j]==1&&map[i+1][j]==1&&map[i][j+1]==1&&map[i+1][j+1]==1)
                answer++;
        }
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    findCnt();

    return 0;
}