#include<iostream>
#include<queue>
using namespace std;

/*
    정렬..!
    우선순위 큐를 사용 => O(logN)
    큐에 들어있는 숫자의 개수(a)
    * 짝수면 인덱스 a/2 - 1 , a/2의 값들 비교해서 더 작은 값 말하기
    * 홀수면 인덱스 a/2의 값 말하기
    * 큐 두개 사용
    
    * 최대가 top인 큐와 최소가 top인 큐 두개를 선언
    * 규칙1) 최대큐의 크기는 최소큐의 크기보다 하나 더 크거나 같다
    * 규칙2) 최대큐의 원소들은 최소큐의 원소들보다 작거나 같다
            만약 규칙2가 성립하지 않으면 각각의 큐의 top을 swap해준다
    *** 두 개의 규칙을 유지하면 최대큐의 top값이 항상 중간값이 된다 ***
*/
priority_queue<int, vector<int>, less<int>> pq1; // 내림차순
priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순
void solution(){
    
    if(pq1.top()>pq2.top())
    {
        int a = pq1.top(); pq1.pop();
        int b = pq2.top(); pq2.pop();

        pq1.push(b);
        pq2.push(a);
    }
    cout<< pq1.top()<<"\n"; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin>>N;
    
    for(int i = 0; i<N; i++)
    {
        int a;
        cin>>a;
        if(i==0) 
        {
            pq1.push(a);
            cout<<a<<"\n";
            continue;
        }
        else if(i==1) pq2.push(a);
        else if(pq1.size()==pq2.size()) pq1.push(a);
        else if(pq1.size()-pq2.size()==1) pq2.push(a);

        solution();
    }
    return 0;
}