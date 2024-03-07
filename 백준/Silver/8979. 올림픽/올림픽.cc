#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    정렬
*/
struct Medal{
    int id,g,s,b;

};
bool cmp(Medal a, Medal b){
    if(a.g<b.g) return false;
    else if(a.g==b.g)
    {
        if(a.s<b.s)return false;
        else if(a.s==b.s)
        {
            if(a.b<b.b)return false;
        }
    }
    return true;
}
int N,M;
vector<Medal> v;
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
    {
        int id,g,s,b;
        cin>>id>>g>>s>>b;
        v.push_back({id,g,s,b});
    }
    sort(v.begin(), v.end(), cmp);
    // for(int i = 0; i<N; i++)
    // {
    //     cout<<v[i].g<<","<<v[i].s<<","<<v[i].b<<"\n";
    // }
}
void solution(){

    int rank[1001],add=1;
    rank[v[0].id]=1;
    if(v[0].id==M)
    {
        cout<<rank[M];
        return;
    }
    for(int i = 1; i<N; i++)
    {
        int id=v[i-1].id, g=v[i-1].g, s=v[i-1].s, b=v[i-1].b;
        int nid=v[i].id, ng=v[i].g, ns=v[i].s, nb=v[i].b;
        if(ng==g&&ns==s&&nb==b)
        {
            add++;
            rank[nid]=rank[id];
        }
        else
        {
            rank[nid]=rank[id]+add;
            add=1;
        }
        if(nid==M)
        {
            cout<<rank[nid];
            return;
        }
    }


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}