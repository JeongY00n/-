#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
    맥주 한 박스에 20개
    but, 박스에 맥주를 20개까지만 담을 수 있음
        * 편의점에 도착하면 빈 병은 버리기
        * 맥주를 박스에 가득 채우기!
    50미터마다 맥주 한 병씩 마셔야함
    중간에 맥주가 바닥이 나면 sad
    아니면 happy
    
    20*50 = 1000 이동할 거리가 1000 초과이면 이동 불가 sad
*/

int n;
pair<int, int> home, store[101], festival;
void init(){
    cin>>n;
    cin>>home.first>>home.second;
    for(int i = 1; i<=n; i++)
        cin>>store[i].first>>store[i].second;
    cin>>festival.first>>festival.second;

    
}

void bfs(){
    queue<pair<int, int>> q;
    q.push(home);

    int visited[101]={0};

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        int y = now.first;
        int x = now.second;

        if(abs(festival.first-y)+abs(festival.second-x)<=1000)
        {
            cout<<"happy\n";
            return;
        }
        for(int i = 1; i<=n; i++)
        {
            if(visited[i]==1)continue;
            else if(abs(store[i].first-y)+abs(store[i].second-x)<=1000)
            {
                visited[i]=1;
                q.push(store[i]);
            }
        }

    }

    cout<<"sad\n";
    

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    for(int tc=0; tc<T; tc++)
    {
        init();
        bfs();
        
    }

    return 0;
}