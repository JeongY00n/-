#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    마을을 두개로 나누고 두 마을을 잇는 길은 제거
    각 마을에서 두 집을 연결하는 경로가 항상 존재하면서,
    길의 유지비가 최소가 되도록 하고싶다

    각 집에서 다른 집까지 이동하는데 지나가는 길의 최소 유지비

    최소 스패닝 트리에서 노드의 개수-2까지만 연결
*/

struct Coord{
    int h1,h2,cost;
};
bool cmp(Coord A, Coord B){
    return A.cost<B.cost;
}
int N,M;
vector<Coord> v;
int house[100001];

void init(){
    cin>>N>>M;
    for(int i = 0; i<M; i++)
    {
        int h1,h2,cost;
        cin>>h1>>h2>>cost;
        v.push_back({h1,h2,cost});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 1; i<=N; i++)
        house[i]=i;
}

int Find(int h){
    if(h==house[h]) return h;
    return house[h]=Find(house[h]);
}
bool linked(int h1, int h2){
    h1 = Find(house[h1]);
    h2 = Find(house[h2]);

    // 이미 연결되어있는 경우
    if(h1==h2)  return false;
    else if(h1>h2) house[h1]=h2;
    else if(h1<h2) house[h2]=h1;

    return true;
}

void solution(){

    int answer=0, cnt=0;

    for(int i = 0; i<M; i++)
    {
        // 두 개의 마을로 분리되면서, 각 마을의 집들이 모두 연결된 경우
        if(cnt==N-2)
            break;
        int h1=v[i].h1;
        int h2=v[i].h2;
        int cost=v[i].cost;
        if(linked(h1,h2))
        {
            answer+=cost;
            cnt++;
        }
    }
    cout<<answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}