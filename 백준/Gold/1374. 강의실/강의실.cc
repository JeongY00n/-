#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int start, end;
};


int n, cnt;
// 먼저 종료되는 강의 순으로 정렬
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> lecture;
// 종료시간에 대한 큐
// greater<int> 정렬 => 오름차순 정렬
priority_queue<int, vector<int>, greater<int>> tq;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num, start, end;
        cin >> num >> start >> end;
        lecture.push({ start, end });
    }
}

void solution() {
    while(!lecture.empty()){
        pair<int, int> now = lecture.top();
        lecture.pop();

        if(tq.empty()){
            tq.push(now.second);
        }
        else{
            // 만약 강의가 종료된 경우 종료된 강의 pop
            if(now.first >= tq.top())
            {
                tq.pop();
                tq.push(now.second);
            }
            // 강의가 종료되지 않은 경우
            else{
                tq.push(now.second);
            }
        }
    }
    // 진행 중인 강의들
    cout<<tq.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}