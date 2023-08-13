#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    수직 방향으로 이동 가능
    idx x1 x2 y
    x1가 더 앞선 순서대로 
    x1이 동일한 경우 y값이 더 작은 순서대로 정렬
    이동 가능하면 같은 그룹으로
    start end 값이 주어지면 같은 그룹인지 확인
*/

struct LINE{
    int idx, x1, x2, y;
}; 
bool cmp(LINE a, LINE b){
    if(a.x1 > b.x1)return false;
    if(a.x1 < b.x1)return true;

    if(a.y > b.y)return false;
    if(a.y < b.y)return true;

    return false;
}

int n,q;
vector<LINE> v;
int parent[100001];

int Find(int x){
    if(x!=parent[x])
        return Find(parent[x]);
    else
        return parent[x];
}

void Union(int x, int y){
    int py = Find(parent[y]);
    int px = Find(parent[x]);

    if(py > px)
        parent[y]=px;
    else
        parent[x]=py;
}

void Findparent(){
    for(int i = 1; i<=n; i++)
        parent[i]=i;
    
    
    for(int i = 0; i<n; i++)
    {
        int nowidx = v[i].idx;
        int nowx1 = v[i].x1;
        int nowx2 = v[i].x2;
        int nowy = v[i].y;

        for(int j = i+1; j<n; j++)
        {
            int nextidx = v[j].idx;
            int nextx1 = v[j].x1;
            int nextx2 = v[j].x2;
            int nexty = v[j].y;
            if(nowx1<=nextx1&&nextx1<=nowx2 || nextx1<=nowx2&&nowx2<=nextx2)
                Union(nowidx, nextidx);
            else
                break;
            
        }
    }
}

void solution(int start, int end){
    if(Find(start)==Find(end))cout<<"1\n";
    else cout<<"0\n";
}
void init(){
    cin>>n>>q;
    for(int i = 1; i<=n; i++){
        int x1, x2, y;
        cin>>x1>>x2>>y;
        v.push_back({i, x1, x2, y});
    }
    sort(v.begin(), v.end(), cmp);

    Findparent();

    for(int i = 0; i<q; i++){
        int start, end;
        cin>>start>>end;
        solution(start, end);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    return 0;
}