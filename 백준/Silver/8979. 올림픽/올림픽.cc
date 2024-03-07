#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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
int g, s, b;
void init(){
    cin>>N>>M;
    for(int i = 0; i<N; i++)
    {
        int nid,ng,ns,nb;
        cin>>nid>>ng>>ns>>nb;
        v.push_back({nid,ng,ns,nb});
        if(nid==M)
        {
            g=ng;s=ns;b=nb;
        }
    }
    // sort(v.begin(), v.end(), cmp);
    // for(int i = 0; i<N; i++)
    // {
    //     cout<<v[i].g<<","<<v[i].s<<","<<v[i].b<<"\n";
    // }
}
void solution(){

    int rank=1;

    for(int i = 0; i<N; i++)
    {
        int nid=v[i].id, ng=v[i].g, ns=v[i].s, nb=v[i].b;

        if(ng>g)
            rank++;
        else if(ng==g)
        {
            if(ns>s)
                rank++;
            else if(ns==s)
            {
                if(nb>b)
                    rank++;
            }
        }
    }

    cout<<rank;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}