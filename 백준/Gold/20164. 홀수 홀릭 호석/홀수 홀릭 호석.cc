#include<iostream>

using namespace std;
/*
    1,000,000,000 10억
    
    1자릿수인 경우는 종료
    2자릿수인 경우는 두 수를 합하고
    3자릿수 이상인 경우는 세 개의 수로 나누어서 합한다
    => 3자리로 나누는 경우의 수를 확인하여 최소와 최대를 확인한다

    123456 => 6자리수
    1 2 3456
    1 23 456
    1 234 56
    1 2345 6
    12 3 456
    12 34 56
    12 345 6
    123 4 56
    123 45 6
    1234 5 6

    100000의 몫
    10000의 몫
    10000의 나머지

    1000의 몫
    1000의 나머지

    100의 몫
    100의 나머지

    10의 몫
    10의 나머지

    홀수..

*/
int num, mini=2e9, maxi;
int oddnumber(int n){
    int cnt = 0;
    for(int x = n; x>0; x/=10){
        if(x%10%2!=0)cnt++;
    }
    return cnt;
}

pair<int, int> makenumber(int n, int y, int x){
    int first = n/y;
    int second = n%y/x;
    int third = n%y%x;
    int cnt = 0;

    cnt+=oddnumber(first);
    cnt+=oddnumber(second);
    cnt+=oddnumber(third);
    
    n = first+second+third;
    return {n, cnt};
}

void solution(int n, int cnt){
    if(0<=n&&n<10)
    {
        if(oddnumber(n))
        {
            cnt++;
        }
        maxi = max(maxi, cnt);
        mini = min(mini, cnt);
        return;
    }
    else if(10<=n&&n<100)
    {
        int first = n/10;
        int second = n%10;

        cnt+=oddnumber(first);       
        cnt+=oddnumber(second);
        solution(first+second, cnt);

        return;
    }
    else if(n>=100)
    {
        int x=1;
        // x는 n의 자릿수보다 한 자릿수 더 크게 종료됨
        // int의 범위를 벗어날 수도 있으므로 x<=n/10으로 계산
        for(x = 1; x<=n/10; x*=10)
            ;

        // 세 자리 수 나누기
        for(int i = x; i>=100; i/=10)
        {
            for(int j = i/10; j>=10; j/=10)
            {
                pair<int, int> a = makenumber(n,i,j);
                solution(a.first, cnt+a.second);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>num;
    solution(num, 0);
    cout<<mini<<" "<<maxi;
    return 0;
}
