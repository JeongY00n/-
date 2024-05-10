#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int n,num1[1000000], num2[1000000];
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>num1[i];
        num2[i]=num1[i];
    }
    sort(num2, num2+n);
}
unordered_map<string, int> cnt; // num배열의 value값이 아닌 idx로 개수 체크(숫자가 최대 10억이므로)
void counting(int idx){
    int value = num2[idx];
    int i = idx-1;
    while(i>=0)
    {
        if(num2[i]==value)
        {
            cnt[to_string(num2[idx])]=cnt[to_string(num2[i])];
            break;
        }
        if(num2[i]<value)
        {
            cnt[to_string(num2[idx])]=cnt[to_string(num2[i])]+1;
            break;
        }
        i--;
    }
}
void solution(){
    for(int i = 0; i<n; i++)
        counting(i);
    for(int i = 0; i<n; i++)
        cout<<cnt[to_string(num1[i])]<<" "; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}