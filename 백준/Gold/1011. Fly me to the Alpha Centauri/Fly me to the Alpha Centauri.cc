#include<iostream>
#include<cmath>
using namespace std;

/*
    이동거리 k 광년 이동한 후에는
    k-1 k k+1 광년 이동가능
    시작과 끝은 반드시 1광년

    0 1 2 3
      1 1 1 => 3
    0 1 2 3 4 5 6 7 
      1   2   2 1 1
      1 1   2   2 1 => 7
    1 2 3 4 5 
      1   2 1 => 4

    == 아래와 같은 규칙을 가짐 ==
    1 2 1 => 4광년 이동(2^2), 3번(2*2-1)
    1 2 3 2 1  => 9광년 이동(3^2), 5번(3*2-1)
    1 2 3 4 3 2 1 => 16광년 이동(4^2), 7번(4*2-1)

  13광년 이동을 위해서는, 9광년 이동에서(+4)
  -> 4 > 3 이므로 (2, 2) or (3, 1)으로 나눠서
  24광년 이동을 위해서는, 16광년 이동에서 (+8)
  -> 8 > 4 이므로 (4, 4)로 계산

    n*n : 25 36 49 64
    n*2 : 10 12 14 16
     +  : 35 48 63 
*/
long long x,y;
void solution(){
    long long maxi=0;
    long long answer;

    while(maxi*maxi <= y-x)
        maxi++;
    maxi--;

    long long diff = y-x - maxi*maxi;
    long long add = ceil((double)diff/(double)maxi);

    answer = maxi*2 - 1 + add;
    cout<<answer<<"\n";

}
/*
1
0 2147483647 => 합을 계산하다보면 int범위를 벗어나게됨 => long long 으로
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    for(int tc = 0; tc < T; tc++)
    {
        cin >>x>>y;
        solution();  
    }
    return 0;
}