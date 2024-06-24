#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    (n-1)!
    균등한 우주 쌍 찾기
    idx를 같이 저장하고 값에 대해서 정렬
*/

int n,m;
vector<pair<int,int>> planet[10000];
void init(){
    cin>>m>>n;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            int size;
            cin>>size;
            planet[i].push_back({size, j});
        }
        sort(planet[i].begin(), planet[i].end());
    }
}
void solution(){
    int visited[100][100]={0};
    int cnt=0;
    for(int i = 0; i<m; i++)
    {
        for(int j = i+1; j<m; j++)
        {
            int flag=0;

            for(int a = 0; a<n; a++)
            {
                if(planet[i][a].second != planet[j][a].second)
                {
                    flag=1;
                    break;
                }
                if(a!=n-1)
                {
                    if(planet[i][a+1].first - planet[i][a].first>0)
                    {
                        if(planet[j][a+1].first - planet[j][a].first==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(planet[i][a+1].first - planet[i][a].first==0)
                    {
                        if(planet[j][a+1].first - planet[j][a].first>0)
                        {
                            flag=1;
                            break;
                        }
                    }

                }
            }
            if(!flag)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}