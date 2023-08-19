#include<iostream>
#include <stdlib.h>
using namespace std;

/*
    모든 경우 확인
    이동하면서 좌-다리 우-다리 다리x 의 경우를 모두 확인해서 추가해야하는 다리의 갯수를 확인한다
    - 두 가로선이 연속하거나 서로 접하면 안됨

*/
int n,m,h;
int bridge[31][31]={0};

void init(){
    cin>>n>>m>>h;
    for(int i = 0; i<m; i++)
    {   
        int row,col;
        cin>>row>>col;
        bridge[row][col]=1;
    }
}

bool Check(){
  for (int col = 1; col <= n; col++) {
    int cur = col;
    for (int row = 1; row <= h; row++) {
      if (bridge[row][cur - 1]) cur--;
      else if (bridge[row][cur]) cur++;
    }
    if (cur != col) return false;
  }
  return true;
}

int answer=2e9;

void solution(int idx, int cnt){
    if(cnt==4) return;

    if(Check()){
        answer = min(answer,cnt);
        return;
    }

    for(int row=idx; row<=h; row++)
    {
        for(int col = 1; col<n; col++)
        {
            if(bridge[row][col]==1)continue;
            if(bridge[row][col-1]==1)continue;
            if(bridge[row][col+1]==1)continue;

            bridge[row][col]=1;
            solution(row, cnt+1);
            bridge[row][col]=0;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution(1, 0);
    if(answer == 2e9) cout<<"-1";
    else cout<<answer;
    return 0;
}