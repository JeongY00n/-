#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    3월 1일부터 11월 30일까지 
    피는 날이 빠른 순서대로 정렬하고 
    시작일이 동일한 경우, 지는 날이 늦은 순으로 정렬
    지는 날과 다음 두 개의 꽃의 피는 날들을 비교해서
    지난 날과 같거나 더 빠른 날이 있다면 그 둘의 지는 날이 더 늦은 날로 선택
*/


int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first>b.first)return false;
    else if(a.first<b.first)return true;
    else
    {
        if(a.second<b.second)return false;
        if(a.second>b.second)return true;
        
        return false;
    }
}
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int sm,sd,em,ed;
        cin>>sm>>sd>>em>>ed;
        int start = sm*100+sd;
        int end = em*100+ed;
        v.push_back({start,end});
    }
    sort(v.begin(), v.end(),cmp);
}

pair<int,int> findNext(int end, int idx){
    int next_idx=-1, next = end;
    
    // 종료일보다 빠르거나 같은 날에 피는 꽃이 없다면 종료
    while(idx<n)
    {
        if(end>=v[idx].first)
        {
            //cout<<v[idx].sm<<","<<v[idx].sd<<"\n";
            // 조건에 해당되는 꽃이 다른 꽃이 지는 날보다 늦은 경우
            if(next<v[idx].second)
            {
                next = v[idx].second;
                next_idx = idx;
            }
        }
        else
            return {next_idx,idx-1};

        idx++;
    }
    
    return {next_idx,n-1};

}

void solution(){
    int cnt = 0;
    
    // 1월 1일 부터 3월 1일 까지
    int start = 101;
    int end = 301;

    for(int i = 0; i<n; i++){
        //cout<<v[i].first<<","<<v[i].second<<"\n";
        if(end>=1201)break;
        pair<int,int> a = findNext(end,i);
        int idx = a.first;

        if(idx==-1)break;
        else
        {
            cnt++;
            start = v[idx].first;
            end = v[idx].second;
            i = a.second;
            
            //cout<<sm<<","<<sd<<","<<em<<","<<ed<<"\n";
        }
    }

    if(end<1201)
        cout<<0;
    else
        cout<<cnt;
    
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
2,15,3,23
2,28,4,25 .
4,12,6,5 .
5,2,5,31
6,3,6,15 .
6,15,9,27 .
6,15,9,3
7,14,9,1
9,14,12,24 .
10,5,12,31
*/