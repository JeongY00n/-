#include<iostream>
#include<vector>

using namespace std;

/*
자식 노드가 끊긴 경우

*/
int n, del, cnt, pp;
vector<int> graph[50];

void init(){
    cin>>n;
    int parent=0;
    for(int i = 0; i<n; i++)
    {
        cin>>parent;
        if(parent==-1){pp = i; continue;}
        graph[parent].push_back(i);
    }
    cin>>del;
}

void solution(int idx, int p_size){
    if(idx==del)
    {
        if(p_size==1) cnt++;
        return;
    }

    if(size(graph[idx])==0) cnt++;
    for(int i = 0; i<size(graph[idx]); i++)
    {
        solution(graph[idx][i], size(graph[idx]));
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution(pp,size(graph[pp]));
    cout<<cnt;
    return 0;
}