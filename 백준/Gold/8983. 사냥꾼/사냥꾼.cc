#include<iostream>
#include<algorithm>
using namespace std;

int m,n,l;
int shoot[100000];
pair<int, int> animal[100000]; //(x,y)
int answer;
void init(){
    cin>>m>>n>>l;
    for(int i = 0; i<m; i++)
        cin>>shoot[i];
    for(int i = 0; i<n; i++)
        cin>>animal[i].first>>animal[i].second; 

    sort(shoot, shoot+m);
}

void solution(){

    for(int i = 0; i<n; i++)
    {
        int left=0,right=m-1; // 사대 좌표
        while(left<=right){
            int mid = (right+left)/2;
            
            if(abs(shoot[mid]-animal[i].first)+animal[i].second > l)
            {
                if(shoot[mid]-animal[i].first<0)
                    left=mid+1;
                else
                    right=mid-1;
            }
            else
            {
                answer++;
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    solution();
    cout<<answer;
    return 0;
}