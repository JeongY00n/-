#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*


*/
int t,n;
string number[10001];

void init(){
    cin>>n; 
    for(int i = 0; i<n; i++)
        cin>>number[i];
    
    sort(number, number+n);
    
}
bool solution(){
   
    for(int i = 0; i<n; i++)
    {
        if(number[i+1].find(number[i])==0)
            return false;
    }

    return true;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for(int i = 0; i<t; i++)
    {
        init();
        if(solution())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }  

    return 0;
}