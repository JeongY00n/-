#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n; 
int num[1000]={0};
vector<int> sum;

bool binary_search(int f){
    int left=0, right=sum.size()-1;

    while(left<=right){
        int mid = (left+right)/2;

        if(sum[mid]==f)
            return true;
        
        if(sum[mid]>f)
            right=mid-1;
        else
            left=mid+1;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>num[i];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            sum.push_back(num[i]+num[j]);
        
    sort(num, num+n);
    sort(sum.begin(), sum.end());


    //x+y  = k-z;
    for(int k = n-1; k>=0; k--){
        for(int z = k; z>=0; z--){
            if(binary_search(num[k]-num[z])){
                cout<<num[k];                
                return 0;
            }
        }
    }

    return 0;
}