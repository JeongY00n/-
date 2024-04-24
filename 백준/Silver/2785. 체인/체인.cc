#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,answer=0;
    vector<int>v;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int l;cin>>l;
        v.push_back(l);
    }
    
    sort(v.begin(), v.end());

    int remain = n;
    for(int i = 0; i<n; i++)
    {
        if(remain==0)break;
        if(v[i]<=remain-2)
        {
            answer+=v[i];
            remain-=(1+v[i]);
        }
        else
        {
            answer+=remain-1;
            break;
        }
    }

    cout<<answer;
    
    return 0;
}