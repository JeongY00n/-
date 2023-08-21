#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    두 선거구로 나눠서 인구 차이의 최솟값 계산
    각 선거구는 연결되어 있어야 한다.
    모든 경우 확인
*/


int n, people[11], total, answer = 2e9;
vector<int> v[11];
int visited[11];

void init(){
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        cin>>people[i];
        total+=people[i];
    }
    for(int i = 1; i<=n; i++)
    {
        int cnt;
        cin>>cnt;
        for(int j = 0; j<cnt; j++)
        {
            int link;
            cin>>link;
            v[i].push_back({link});
        }
    }
}

// 가능한 방법인지 확인(연결되어 있는 지)
bool check(int ok){
    int start;
    int no;
    if(ok==1) no = 0;
    else no = 1;
    for(int i = 1; i<=n; i++)
    {
        if(visited[i]==ok)
        {
            start = i;
            break;
        }
    }
    for(int i = start+1; i<=n; i++)
    {
        int flag=0;

        queue<int> q;
        q.push({start});
        int vcheck[11]={0};
        vcheck[start]=1;

        if(visited[i]==ok){
            while(!q.empty()){
                int now = q.front();
                q.pop();
                
                if(now == i)flag=1;
                for(int j = 0; j<v[now].size(); j++)
                {
                    if(visited[v[now][j]]==no)continue;
                    if(vcheck[v[now][j]]==1)continue;
                    q.push({v[now][j]});
                    vcheck[v[now][j]]=1;
                }
            }
            if(!flag)return false;
        }
    }
    return true;
}
/*
    조합 개수 => n/2까지만 구하기

*/
void solution(int depth, int r, int sum){
    if(depth == r){
        if(check(1) && check(0))
            answer = min(answer, abs(total-sum-sum));
        return;
    }

    for(int i = 1; i<=n; i++){
        if(visited[i]==1)continue;
        visited[i]=1;
        solution(depth+1, r, sum+people[i]);
        visited[i]=0;
    }
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i = 1; i<=n/2; i++)
    {
        solution(0,i,0);
    }

    if(answer==2e9) cout<<-1;
    else cout<<answer;

    return 0;
}