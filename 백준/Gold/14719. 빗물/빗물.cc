#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
w의 idx에 대해 반복문을 돌리면서
idx의 좌측 최대값, 우측 최대값을 확인
idx 위치에 고일 수 있는 물의 양을 계산
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
