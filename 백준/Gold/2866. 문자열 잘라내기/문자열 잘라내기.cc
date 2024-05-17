#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int n,m;
char str[1000][1000];
void init(){
    cin>>n>>m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>str[i][j];
}
unordered_map<string, int> h;
void make_hash(){
    for(int i = 0; i<m; i++)
    {
        string a="";
        for(int j = 0; j<n; j++)
        {
            a+=str[j][i];
        }
        if(h.find(a)==h.end())
            h[a]=1;
        else
            continue;
    }
}

void solution(){
    make_hash();
    int idx=0;
    int flag=0;

    while(idx<n){
        unordered_map<string, int> hh;
        for(auto x:h)
        {
            string s = x.first.substr(1);
            if(hh.find(s)==hh.end())
                hh[s]=1;
            else
            {
                flag=1; 
                break;
            }
        }
        if(flag) break;
        idx++;
        h = hh;
    }

    cout<<idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}