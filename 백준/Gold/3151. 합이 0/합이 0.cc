#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, map[10000], mini=2e9, maxi;
void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
    {
        cin>>map[i];
        maxi = max(maxi, map[i]);
        mini = min(mini, map[i]);
    }
    sort(map, map+N);
}

long long upper_bound(int idx, int sum){
    long long left=idx, right=N;
    //cout<<"left"<<left<<" ";

    while(left<right){
        long long mid = (left+right)/2;

        if(map[mid]>sum)
            right=mid;
        else
            left=mid+1;
        //cout<<right<<" ";
    }
    //cout<<"\n";
    //cout<<right<<" ";
    return right;
}

long long lower_bound(int idx, int sum){
    long long left=idx, right=N;
    while(left<right){
        long long mid = (left+right)/2;

        if(map[mid]>=sum)
            right=mid;
        else
            left=mid+1;
    }
    //cout<<right<<"\n";
    return right;
}

void solution(){
    vector<int> v;
    long long answer=0;
    int left=0,right=1;
    while(left<N){
        int sum = (map[left]+map[right])*-1;
        
        if(mini<=sum&&sum<=maxi)
        {
            int cnt1=upper_bound(right+1,sum);
            int cnt2=lower_bound(right+1,sum);
            answer += cnt1-cnt2;
            right++;
        }
        else if(maxi<sum*-1)
        {
            left++;
            right=left+1;
        }
        else
            right++;
        
        // 학생 수 범위를 벗어난 경우
        if(right>=N)
        {
            left++;
            right=left+1;
        }
        
    }

    cout<<answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}