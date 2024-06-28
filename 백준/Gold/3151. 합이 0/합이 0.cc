#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, map[10000];
void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
        cin>>map[i];
    sort(map, map+N);
}

long long upper_bound(int idx, int sum){
    long long left=idx, right=N;

    while(left<right){
        long long mid = (left+right)/2;

        if(map[mid]>sum)
            right=mid;
        else
            left=mid+1;
        //cout<<right<<" ";
    }
    // cout<<"\n";
    // //cout<<right<<" ";
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
    return right;
}

void solution(){
    vector<int> v;
    long long answer=0;
    int left=0,right=1;
    while(left<N){
        int sum = map[left]+map[right];
        
        int cnt1=upper_bound(right+1,sum*-1);
        int cnt2=lower_bound(right+1,sum*-1);
        answer += cnt1-cnt2;
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