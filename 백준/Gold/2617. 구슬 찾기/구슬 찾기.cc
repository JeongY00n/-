#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

/*
    2 1
    4 3 
    4 2
    5 1

    모든 번호에 대해서 dfs
    
    무거운 것 가벼운 것이 n/2개보다 많은 경우 될 수 없음
    1보다 무거운 것 2 4 5
    2보다 무거운 것 4
    3보다 무거운 것 4
    4보다 무거운 것 
    5보다 무거운 것

    1보다 가벼운 것 
    2보다 가벼운 것 1
    3보다 가벼운 것 
    4보다 가벼운 것 1 2 3
    5보다 가벼운 것 1

*/
int n,m;
vector<int> v1[100], v2[100];
void init(){
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
}
int bigger[100], smaller[100];
int visited1[100], visited2[100];
void solution1(int now, int num){
    for(int i = 0; i<v1[now].size(); i++)
    {
        if(visited1[v1[now][i]]==1)continue;
        smaller[num]++;
        visited1[v1[now][i]]=1;
        solution1(v1[now][i],num);
    }
}
void solution2(int now, int num){
    
    for(int i = 0; i<v2[now].size(); i++)
    {
        if(visited2[v2[now][i]]==1)continue;
        bigger[num]++;
        visited2[v2[now][i]]=1;
        solution2(v2[now][i], num);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i = 1; i<=n; i++)
    {
        memset(visited1,0,sizeof(visited1));
        memset(visited2,0,sizeof(visited2));
        solution1(i,i);
        solution2(i,i);
    }
    int answer=0;
    for(int i = 1; i<=n; i++)
    {
        if(bigger[i]>n/2||smaller[i]>n/2)
            answer++;
    }
    cout<<answer;
    return 0;
}