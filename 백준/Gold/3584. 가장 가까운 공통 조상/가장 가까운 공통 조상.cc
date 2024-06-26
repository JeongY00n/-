#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int N;
int p[10001], check[10001];
int n1, n2, answer;
void init(){
    cin>>N;
    memset(check, 0, sizeof(check));

    for(int i = 0; i<N-1; i++)
    {
        int from,to; cin>>from>>to;
        p[to]=from;
    }
    cin>>n1>>n2;
}

void findParent(int node){
    queue<int> q;
    q.push(node);
    check[node]=1;

    while(!q.empty()){
        int now = q.front(); q.pop();
        if(check[now])
            answer=now;
        if(p[now]==0)continue;

        if(check[p[now]])
        {
            answer=p[now];
            break;
        }
        check[p[now]]=1;
        q.push(p[now]);
    }
}
void solution(){
    findParent(n1);
    findParent(n2);

    cout<<answer<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;

    for(int tc=0; tc<T; tc++)
    {
        init();
        solution();
    }
    return 0;
}