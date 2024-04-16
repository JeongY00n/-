#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
long long K;
long long map[1000001]; // 점의 개수(2,3,4,5 : 4개)가 아니라 길이를 계산 (2,3,4,5 : 3) 
int maxi=0, mini=1e9;
vector<pair<int, int>> v;
void init(){
    cin>>N>>K;
    for(int i = 0; i<N; i++)
    {
        int a,b; cin>>a>>b;
        map[a]++;
        map[b]--;
        
        maxi=max(maxi, b);
        mini=min(mini, a);
    }

    for(int i = 1; i<=maxi; i++)
    {
        map[i]+=map[i-1];
    }
}
void solution(){
    int left=0, right=mini;
    long long sum=0; 
    int flag=0;

    while(left<=right&&right<=maxi){

        //cout<<left<<","<<right<<","<<sum<<"\n";
        // 구간에 포함되는 수직선의 길이가 K보다 작은 경우
        // right++
        if(sum<K)
        {
            // 해당 점에 위치하는 수직선의 개수 더하기
            sum+=map[right];
            right++;

        }
        // 구간에 포함되는 수직선의 길이가 K보다 큰 경우
        // left++
        else if(sum>K)
        {
            sum-=map[left];
            left++;
        }
        if(sum==K)
        {
            flag=1;
            break;
        }
    }

    if(!flag)
    {
        left=0; right=0;
    }
    

    cout<<left<<" "<<right;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}