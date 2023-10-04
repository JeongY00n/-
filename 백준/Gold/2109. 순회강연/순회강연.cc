#include<iostream>
#include<queue>
using namespace std;

/*
    --(X)d일에 강연을 요구하는 대학마다의 p강연료 저장
    --(O)d일안에 강연을 요구하는 대학마다의 p강연료 저장
    
    d를 먼저 내림차순으로 정렬한 다음에 p를 내림차순으로 정렬
    마지막 d부터 시작해서
    해당 day에 강연을 하면 pop
    해당 day에 다른 강연보다 강연료가 적은 경우는 q에 p강연료만 push하고 pq에서는 pop
    => day 앞으로는 언제는 강연해도 되므로 가장 큰 금액 순으로 q를 정렬
    
    
*/

struct LECTURE{
    long long p;
    int d;

    // d 내림차순 p 내림차순 정렬
    bool operator<(const LECTURE&other)const{
        if(d > other.d)return false;
        if(d < other.d)return true;

        if(p > other.p)return false;
        if(p < other.p)return true;

        return false;
    }
};

int n, end_d=0;
priority_queue<LECTURE> pq;
long long maxi[100001]={0};
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int d;
        long long p;
        cin>>p>>d;
        pq.push({p,d});
        end_d=max(end_d, d);
        maxi[d]=max(maxi[d],p);
    }


}
void solution(){
    long long answer=0;
    priority_queue<int> q;
    for(int day = end_d; day>=1; day--)
    {
        if(pq.empty())
        {
            if(!q.empty()){
                answer+=q.top();
                q.pop();
            }
            continue;
        }

        // day가 더 작은 경우
        if(day<pq.top().d)
        {
            // day가 클 때까지
            while(day<=pq.top().d)
            {
                q.push(pq.top().p);
                pq.pop();
                if(pq.empty())break;
            }

            answer+=q.top();
            q.pop();
        }
        // day가 더 큰 경우
        else if(day>pq.top().d)
        {
            if(q.empty())continue;
            else
            {
                answer+=q.top();
                q.pop();
            }
        }
        // day가 같은 경우
        else if(day==pq.top().d)
        {
            if(q.empty()){
                answer+=pq.top().p;
                pq.pop();
            }
            else
            {
                if(pq.top().p < q.top())
                {
                    answer+=q.top();
                    q.pop();
                    q.push(pq.top().p);
                    pq.pop();
                }
                else
                {
                    answer+=pq.top().p;
                    pq.pop();
                }
            }
        }
        
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}


/*
76 28 48 72 42 58 36 56 7 45 38 85 71 95 67 55 100 1 78 16 
20 20 18 15 14 12 12 11 10 9  9  8  6  5  5  4  3  3  2  2



*/