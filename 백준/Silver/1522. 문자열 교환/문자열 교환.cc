#include<iostream>
#include<algorithm>

using namespace std;

/*
    처음과 끝은 서로 인접해있다
    
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str; cin>>str;
    int a_cnt=0;
    int answer=1000;

    for(int i = 0; i<str.size(); i++)
        if(str[i]=='a')
            a_cnt++;

    // 슬라이딩윈도우
    for(int i = 0; i<str.size(); i++)
    {
        // a_cnt길이를 탐색하여 b_cnt가 가장 작은 위치를 탐색하기
        int b_cnt=0;
        int idx=i;
        for(int j = 0; j<a_cnt; j++)
        {
            if(str[idx]=='b')
                b_cnt++;
            idx++;
            idx%=str.size();
        }
        answer=min(answer,b_cnt);
    }
    cout<<answer;
    return 0;
}