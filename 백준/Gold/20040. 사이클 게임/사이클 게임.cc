#include<iostream>

using namespace std;

int N, M;
int parent[500001];

void init(){
    cin>>N>>M;
	for (int i = 0; i < N; i++)
		parent[i] = i;
}

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x]=find(parent[x]);
}

void Union(int y, int x)
{
	y = find(parent[y]);
	x = find(parent[x]);

    if (y >= x) parent[y] = x;
    else parent[x] = y;
}
bool Parent(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		return false;
	return true;
}
void solution(){
    init();

    int flag=0, answer=0;
	for (int i = 0; i < M; i++)
	{
        int y, x; cin>>y>>x;	

        if(!flag){
            if(Parent(y,x))
            {
                answer=i+1;
                flag=1;
            }
            Union(y, x);
        }
	}
	cout << answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

    return 0;	
}