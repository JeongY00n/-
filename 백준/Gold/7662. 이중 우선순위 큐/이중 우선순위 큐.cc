#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

struct cmp1{ // 내림차순
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
};
struct cmp2{ // 오름차순
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq1;
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> pq2;
int check[1000000];
int k, cnt=0;

void init(){
    while(!pq1.empty())
        pq1.pop();
    
    while(!pq2.empty())
        pq2.pop();

    cnt=0;
    memset(check, 0, sizeof(check));
}

void insert(int num, int id){
    pq1.push({num,id});
    pq2.push({num,id});
    check[id]=1;
    cnt++;
}

void del(int num){
    if(cnt==0)return;

    if(num==-1)
    {
        while(check[pq1.top().second]==0 && !pq1.empty())
            pq1.pop();
        
        check[pq1.top().second]=0;
        pq1.pop();
    }
    else if(num==1)
    {
        while(check[pq2.top().second]==0 && !pq2.empty())
            pq2.pop();

        check[pq2.top().second]=0;
        pq2.pop();
    }
    cnt--;
}

void solution(){
    cin>>k;
    char op;
    int num;
    for(int i = 0; i<k; i++)
    {
        cin>>op>>num;
        if(op=='I') insert(num, i);
        if(op=='D') del(num);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    for(int tc=0; tc<T; tc++){
        init();
        solution();

        if(cnt==0) cout<<"EMPTY\n";
        else 
        {
            while(check[pq1.top().second]==0 && !pq1.empty())
                pq1.pop();
            
            while(check[pq2.top().second]==0 && !pq2.empty())
                pq2.pop();
            
            cout<<pq2.top().first<<" "<<pq1.top().first<<"\n";
        }
    }

    return 0;
}