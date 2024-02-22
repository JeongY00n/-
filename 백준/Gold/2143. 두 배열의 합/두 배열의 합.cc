#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
    T:10억
    
*/

int T,n,m;
long long A[1000], B[1000];
vector<long long> aa, bb;
vector<long long> sumA, sumB;
void init(){
    cin>>T>>n;
    for(int i = 0; i<n; i++)
        cin>>A[i];
    for(int i = 0; i<n; i++)
    {
        int sum=A[i];
        sumA.push_back(sum);
        for(int j = i+1; j<n; j++)
        {
            sum+=A[j];
            sumA.push_back(sum);
        }
    }
    sort(sumA.begin(), sumA.end());
    
    cin>>m;
    for(int i = 0; i<m; i++)
        cin>>B[i];
    for(int i = 0; i<m; i++)
    {
        int sum=B[i];
        sumB.push_back(sum);
        for(int j = i+1; j<m; j++)
        {
            sum+=B[j];
            sumB.push_back(sum);
        }
    }
    sort(sumB.begin(), sumB.end());
}

void solution(){
    int a=0,b=0;
    long long answer=0;
    int j = 0;
    for(int i = 0; i<sumA.size(); i++)
    {
        int target = T - sumA[i];
        int lo = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		int hi = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		answer += (hi - lo);
	}

	cout << answer;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}