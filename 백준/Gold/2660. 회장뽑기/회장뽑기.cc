#include<iostream>
#include<queue>
using namespace std;

/*
    각 회원들에 대해 탐색
    2차원배열 생성해서 둘이 친구인지 친구의 친구인지... 확인
*/

int N, friends[51][51], maxicost[51];
queue<pair<pair<int,int>, int>> q;
void init(){
    cin>>N;
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            if(i==j)continue;
            friends[i][j]=100;
        }
    }

    while(1){
        int a,b;
        cin>>a>>b;
        if(a==-1&&b==-1)break;
        friends[a][b]=1;
        friends[b][a]=1;
    }
    
}

void solution(){

    for(int t=1; t<=N; t++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                friends[i][j]=min(friends[i][j], friends[i][t]+friends[t][j]);
    
    vector<int> answer;
    int answerscore=2e9;
    for(int a = 1; a<=N; a++)
    {
        for(int b=1; b<=N; b++)
        {
            if(a==b)continue;
            maxicost[a]=max(maxicost[a], friends[a][b]);
        }
        
        if(answerscore > maxicost[a])
        {
            answer.clear();
            answerscore=maxicost[a];
        }
        if(answerscore==maxicost[a])
        {
            answer.push_back(a);
        }
    }

    cout<<answerscore<<" "<<answer.size()<<"\n";
    for(int i = 0; i<answer.size(); i++)
        cout<<answer[i]<<" ";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}