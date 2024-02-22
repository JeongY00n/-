#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
    눈덩이 4개를 골라서 눈사람 2개를 만들기
    두 눈사람의 키 차이가 작아야함
    
*/

int N;
long long snowball[600];
vector<pair<long long,pair<int, int>>> sum;
void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
        cin>>snowball[i];
    
    for(int i = 0; i<N; i++)
        for(int j = i+1; j<N; j++)
            sum.push_back({snowball[i]+snowball[j],{i,j}});
        
    sort(sum.begin(), sum.end());
    // for(int i = 0; i<sum.size(); i++)
    //     cout<<sum[i].first<<" ";
}
void solution(){
    int left=0, right=1;
    long long answer=2e9;
    int check[600]={0};
    int ly=sum[left].second.first;
    int lx=sum[left].second.second;
    int ry=sum[right].second.first;
    int rx=sum[right].second.second;
    check[ly]=1; check[lx]=1;

    while(right<sum.size())
    {
        ry=sum[right].second.first;
        rx=sum[right].second.second;

        if(check[ry]==1||check[rx]==1)
        {
            right++;
            continue;
        }
        
        answer = min(answer, abs(sum[left].first-sum[right].first));
        check[ly]=0;check[lx]=0;
        left++;
        ly=sum[left].second.first;
        lx=sum[left].second.second;
        check[ly]=1;check[lx]=1;
        right=left+1;
    }

    cout<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}