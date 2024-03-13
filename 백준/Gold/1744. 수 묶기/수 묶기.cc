#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v[51];
int N; 
void init(){
    cin>>N;
    for(int i = 0; i<N; i++)
        cin>>v[i];
    // 내림차순 정렬
    sort(v, v+N, greater<>());
    
}
void solution(){
    int answer=0;
    vector<int> newnum;
    for(int i = 0; i<N; i++)
    {
        // 양수에 대해
        if(v[i]>0){
            // 인덱스+1이 수열의 크기를 넘지 않는 경우
            if(i+1<N){
                int a = v[i]*v[i+1];
                if(v[i]+v[i+1]<a) // 곱한 값이 더 큰 경우
                {
                    newnum.push_back(a);
                    i++;
                }
                else
                    newnum.push_back(v[i]);
            }
            // 수열의 크기를 넘는다는 것은 마지막 인덱스라는 것
            else 
                newnum.push_back(v[i]);
            
        }
        // 음수에 대해
        else{
            for(int j = N-1; j>=i; j--)
            {
                // 인덱스-1이 i와 같거나 같은 경우
                if(j-1>=i){
                    int a = v[j]*v[j-1];
                    if(v[j]+v[j+1]<a) // 곱한 값이 더 큰 경우
                    {
                        newnum.push_back(a);
                        j--;
                    }
                    else
                        newnum.push_back(v[j]);
                }
                // 수열의 크기를 넘는다는 것은 마지막 인덱스라는 것
                else 
                    newnum.push_back(v[j]);
            }
            
            break;
        }
        
    }
    for(int i = 0; i<newnum.size(); i++)
        answer+=newnum[i];

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