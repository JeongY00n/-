#include<iostream>

using namespace std;

/*
    left, right의 초기값은 0부터 시작
    left와 right 사이 원소들의 합이 S를 넘지 않으면 right+1하면서 나아감
    만약 S를 넘는다면 left+1해줌
    합이 S를 넘는 경우에 대해 answer보다 짧은 길이라면 값 갱신
*/

int N,S;
int num[100000], answer=2e9;
void init(){
    cin>>N>>S;
    for(int i = 0; i<N; i++)
        cin>>num[i];
}
void solution(){
    int left=0,right=0,sum=num[0];
    int flag=0;
    int ar,al;
    if(sum>=S) answer = 1;
    while(left<=right){
        if(right==N)break;

        if(!flag){
            right++;
            sum+=num[right];

            if(sum>=S)
            {
                answer = min(answer, right-left+1);
                flag=1;
            }
        }

        else{
            sum-=num[left];
            left++;
            if(sum>=S)
            {
                answer = min(answer, right-left+1);
            }
            else if(sum<S)
            {
                flag=0;
            }
        }
    }

    if(answer==2e9)
        answer = 0;

    cout<<answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}