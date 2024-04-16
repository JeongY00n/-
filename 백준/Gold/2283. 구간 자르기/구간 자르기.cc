#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
long long K;
long long map[1000001]; // 몇개의 수직선이 그어진 점인지 확인
//vector<int> idx[1000001];
int maxi=0;
void init(){
    cin>>N>>K;
    for(int i = 0; i<N; i++)
    {
        int a,b; cin>>a>>b;
        for (int j = a+1; j<=b; j++) map[j]++;
        
        maxi=max(maxi, b);
    }
}
void solution(){
    int left=0, right=0;
    long long sum=0; // 점의 개수(2,3,4,5 : 4개)가 아니라 길이를 계산 (2,3,4,5 : 3) 
    int flag=0;

    // // 구간에 포함되는 점들이 어느 수직선의 점인지 확인
    // // 처음 등장하는 수직선의 점의 경우 -1을 해줌
    // for(int i=0; i<idx[mini].size(); i++)
    // {
    //     cnt[idx[mini][i]]++;
    //     if(cnt[idx[mini][i]]==1)sum--;
    // }
    while(left<=right&&right<=maxi){

        //cout<<left<<","<<right<<","<<sum<<"\n";
        // 구간에 포함되는 수직선의 길이가 K보다 작은 경우
        // right++
        if(sum<K)
        {
            right++;
            // 해당 점에 위치하는 수직선의 개수 더하기
            sum+=map[right];
            // 수직선의 길이는 수직선 점의 개수 -1 이므로
            // 수직선의 번호로 구간에 포함된 수직선의 점의 개수를 파악하여
            // 처음 구간에 들어온 경우 -1을 빼줌
            // for(int i=0; i<idx[right].size(); i++)
            // {
            //     cnt[idx[right][i]]++;
            //     if(cnt[idx[right][i]]==1)sum--;
            // }
        }
        // 구간에 포함되는 수직선의 길이가 K보다 큰 경우
        // left++
        else if(sum>K)
        {
            // for(int i=0; i<idx[left].size(); i++)
            // {
            //     cnt[idx[left][i]]--;
            //     if(cnt[idx[left][i]]==0)sum++;
            // }
            left++;
            sum-=map[left];
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