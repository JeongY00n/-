#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int n, MAP[2][101];
int maxi;

void init(){
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        MAP[0][i]=i;
        cin>>MAP[1][i];
    }
}
vector<int> v;
int flag = 0;

void solution(int idx, int end, int cnt){
    if(cnt == 100)
        return;
    if(idx == end){
        flag = 1;
        return;
    }
    solution(MAP[1][idx], end, cnt+1);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> answer;
    init();
    for(int i = 1; i<=n; i++)
    {   
        flag = 0;
        if(MAP[0][i]==MAP[1][i]){
            answer.push_back(i);
            continue;
        }
        solution(MAP[1][i], i,0);
        if(flag == 1)
        {
            answer.push_back(i);
        }
    }
    
    cout<<answer.size()<<"\n";

    for(int i = 0; i<answer.size(); i++)
        cout<<answer[i]<<"\n";  
    return 0;
}