#include<iostream>
#include<algorithm>

using namespace std;


int n,m;
int bus[101][101];
void init(){
    cin>>n>>m;
    fill(&bus[0][0],&bus[100][101],1e9);
    for(int i = 0; i<m; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;

        bus[from][to]=min(bus[from][to],cost);
    }
}

void solution(){

    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(bus[i][j]>bus[i][k]+bus[k][j])
                    bus[i][j]=bus[i][k]+bus[k][j];
            }
        }
    }
    
    for(int i = 1; i<=n; i++)
        bus[i][i]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(bus[i][j]>=1e9)
                bus[i][j]=0;
            cout<<bus[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}