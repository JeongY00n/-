#include<iostream>
#include<vector>
using namespace std;

/*
    연결고리를 다 묶기 
    한 사람이 여러 파티에 참석하게 되면,
    그 파티에 참석하는 사람들 모두는 진실을 알게되거나 거짓을 알게됨

    진실 여부
    파티에 참여하는 멤버

*/

int n,m,know_truth,answer;
vector<int> party_mem[51]; // 파티 참여자
int parent[51]; // 그룹으로 묶기(진실과 거짓)

int Find(int parent[], int x){
    if(x != parent[x])
        return parent[x] = Find(parent, parent[x]);
    else
        return parent[x];
}

void Union(int parent[], int x, int y){
    int px = Find(parent, parent[x]);
    int py = Find(parent, parent[y]);
    if(px != py)
    {
        if(px < py)
            parent[py]=parent[px];
        else
            parent[px]=parent[py];
    }
}
void init(){
    cin>>n>>m;
    
    for(int i = 1; i<=n; i++)
        parent[i]=i; // 자기 자신으로 분류

    cin>>know_truth;
    for(int i = 0; i<know_truth; i++)
    {
        int id;
        cin>>id;
        parent[id]=0; // 진실을 아는 경우는 0으로 분류
    }

    for(int i = 1; i<=m; i++)
    {
        int party_num, first_id;
        cin>>party_num>>first_id;
        party_mem[i].push_back({first_id});

        for(int j = 0; j<party_num-1; j++)
        {
            int id;
            cin>>id;
            party_mem[i].push_back({id});
            Union(parent, first_id, id); // 파티에 가장 먼저 참여하는 사람을 기준으로 그룹 분류
        }
    }
    
}

void solution(){
    for(int i = 1; i<=m; i++)
    {   
        int flag=0;
        for(int j = 0; j<party_mem[i].size(); j++)
        {
            // 진실 그룹에 속하는 경우
            if(Find(parent, parent[party_mem[i][j]])==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            answer++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<answer;
    return 0;
}