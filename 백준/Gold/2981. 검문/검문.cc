#include<iostream>
#include<algorithm>

using namespace std;

int n, number[100];

// a%b 가 0이라면 b를 출력, 아니면 gcd진행
int gcd(int a, int b){
    return a%b ? gcd(b,a%b) : b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>number[i];

    sort(number, number+n);

    // 최소공배수 구하기
    int temp = number[1]-number[0];
    for(int i = 2; i<n; i++)
        temp = gcd(temp, number[i]-number[i-1]);
    
    vector<int> answer;
    // 약수 구하기
    // 15의 약수 1,3,5,15로 예를 들면,
    // 1*1 <= 15 , if(1 != 15/1) => 1, 15
    // 2*2 <= 15
    // 3*3 <= 15 , if(3 != 15/3) => 3, 5
    // if문 조건문을 사용하는 이유는 4*4와 같은 제곱수에 대한 예외처리를 하기 위함
    // 16의 약수 1,2,4,8,16
    // ..
    // 4*4 <= 16 , if(4 != 16/4) => 4

    for(int i = 1; i*i<=temp; i++)
        if(temp%i==0)
        {
            answer.push_back(i);
            if(i != temp/i) answer.push_back(temp/i);
        }

    sort(answer.begin(), answer.end());

    for(int i = 0; i<answer.size(); i++)
        if(answer[i]!=1)
            cout<<answer[i]<<" ";
    
    return 0;
}