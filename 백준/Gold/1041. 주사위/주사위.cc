#include <iostream>
using namespace std;

long long n;
int dice[8];
long long face3=2e18, face2=2e18, face1=2e18;
long long answer, sum;
long long maxi=0;
void init(){
    cin>>n;
    for(int i = 1; i<=6; i++)
    {    
        cin>>dice[i];
        if(face1 > dice[i])
            face1 = dice[i];
        if(maxi < dice[i])
            maxi = dice[i];
        sum+=dice[i];
    }
}
int visited[8];
void dfs(int idx, int cnt, int sum){
    if(cnt == 3)
    {
        if(face3 > sum)
            face3 = sum;
        return;
    }
    if(cnt == 2)
    {
        if(face2 > sum)
            face2 = sum;
    }

    for(int i = 1; i<=6; i++)
    {
        if(idx+i == 7)continue;
        if(visited[i]==1)continue;
        if(visited[7-i]==1)continue;

        visited[i]=1;
        dfs(i, cnt+1, sum+dice[i]);
        visited[i]=0;
    }


}

void solution(){
    long long calc_face3 = face3 * 4;
    long long calc_face2 = face2 * ((n-2)*4 + (n-1)*4);
    long long calc_face1 = face1 * ((n-2)*(n-2) + (n-2)*(n-1)*4);

    answer = calc_face1 + calc_face2 + calc_face3;
    cout<<answer;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    if(n == 1)
    {
        cout<<sum-maxi;
    }
    else
    {
        dfs(0,0,0);
        solution();
    }
    
    return 0;
}