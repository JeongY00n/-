#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
양끝의 높이를 확인
둘 중 작은 높의 값보다 큰 높이의 벽이 있는 idx 확인
*/

int w,h;
int height[500];

void init(){
    cin>>h>>w;
    for(int i = 0; i<w; i++)
    {
        cin>>height[i];
    }
}

int sum;
void solution(){
    for(int i = 1; i<w-1; i++)
    {   
        int left_max=height[i];
        int right_max=height[i];

        for(int a = i-1; a>=0; a--)
        {
            if(left_max<height[a])
            {
                left_max=height[a];
            }
        }
        for(int b = i+1; b<w; b++)
        {
            if(right_max<=height[b])
            {
                right_max=height[b];
            }
        }

        int maxi = min(left_max, right_max);
        
        sum+=(maxi - height[i]);

    }

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<sum;
    return 0;
}