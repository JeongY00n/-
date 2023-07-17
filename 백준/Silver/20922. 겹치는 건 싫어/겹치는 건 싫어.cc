#include<iostream>
#include<string.h>
using namespace std;

/*
idx 0부터 카운팅
겹치는 숫자가 존재하는 위치부터 다시 카운팅
max값이 
- n과 동일하면 중단
- cnt값이 max 보다 작으면 넘어가기
*/

int N, K, list[200001], counting[100001];
int answer=0;

void init(){
    cin>>N>>K;
    for(int i = 0; i<N; i++)
        cin>>list[i];
}

void solution(){
    int left=0,right=-1;
    while(right != N){
        right++;
        counting[list[right]]++;
        if(counting[list[right]]>K)
        {
            if(right - left > answer) answer = right - left;
            while(counting[list[right]]>K && left<right)
            {
                counting[list[left]]--;
                left++;
            }
        }
    }
    if(right - left > answer) answer = right - left;

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