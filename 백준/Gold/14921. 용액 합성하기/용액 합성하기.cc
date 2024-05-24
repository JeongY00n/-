#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long num[100000];
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>num[i];
    sort(num, num+n);
}
void solution(){
    int left=0, right=n-1;
    long long answer=num[left]+num[right];
    while(left<right){
        long long mix = num[left]+num[right];

        if(mix==0)
        {
            answer=mix;
            break;
        }
        else
        {
            if(abs(answer)>abs(mix))
                answer=mix;
        }

        if(mix>0)
            right--;
        else
            left++;
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