#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    while(!(a==0&&b==0&&c==0))
    {   
        int maxi = max(a,max(b,c));
        int sum=a+b+c;
        // 삼각형의 조건을 만족하지 못하는 경우
        if(maxi>=sum-maxi)
            cout<<"Invalid\n";
        // 세 변의 길이가 모두 다른 경우
        else if(a!=b&&a!=c&&b!=c)
            cout<<"Scalene\n";
        
        // 세 변의 길이가 모두 같은 경우
        else if(a==b&&a==c&&b==c)
            cout<<"Equilateral\n";
        // 두 변의 길이만 같은 경우
        else
            cout<<"Isosceles\n";

        cin>>a>>b>>c;
    }

    return 0;
}