#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

/*
    현재 위치에서 볼 수 있는 건물의 개수와 가장 가까운 건물의 번호
    양 옆이 볼 수 있는 건물의 수
    건물번호
    * 왼쪽방향으로 확인하는 경우에는 내림차순
    * 오른쪽방향으로 확인하는 경우에는 오름차순
    방향 정해서 따로 계산
    주어진 방향에서 본인보다 높은 건물을 찾고 그 건물이 볼 수 있는 건물의 개수에 +1
    후입선출
    가장 늦게 삽입된 번호가 가장 가까운 번호
*/


int N, map[100001];
void init(){
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>map[i];
}
stack<pair<int, int>> stack1, stack2; // 인덱스, 높이
int cnt[100001], idx[100001];
void solution(){

    // 현재위치에서 볼 수 있는 왼쪽 건물
    for(int i = 1; i<=N; i++)
    {
        // 왼쪽 방향에서 현재 건물의 높이보다 높은 건물 찾기
        // 여기서 시간초과 발생
        // while(map[i]>=map[idx] && idx>1)
        //     idx--;
        // 스택으로 유효한 건물의 높이만 비교(높은 건물에 의해 가려진 건물들을 확인할 필요가 없으므로)
        while(!stack1.empty() && stack1.top().second <= map[i])
            stack1.pop();
        
        if(stack1.empty())
        {
            stack1.push({i,map[i]});
            continue;
        }
        cnt[i] += stack1.size();
        idx[i] = stack1.top().first;
        stack1.push({i,map[i]});
    }

    // 현재위치에서 볼 수 있는 오른쪽 건물
    for(int i = N; i>=1; i--)
    {
        // 오른쪽 방향에서 현재 건물의 높이보다 높은 건물 찾기
        while(!stack2.empty() && stack2.top().second <= map[i])
            stack2.pop();
        
        if(stack2.empty())
        {
            stack2.push({i,map[i]});
            continue;
        }
        cnt[i] += stack2.size();
        if(idx[i]==0||abs(idx[i]-i)>abs(stack2.top().first-i))
            idx[i] = stack2.top().first;
        stack2.push({i,map[i]});
    }

    
    // 출력
    for(int i = 1; i<=N; i++)
    {   
        cout<<cnt[i]<<" ";
        
        if(cnt[i]>0)
            cout<<idx[i];
        
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}