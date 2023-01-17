#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int flag = 0;
		char vps[51] = { 0 };
		cin >> vps;

		if (vps[0] == ')') {
			cout << "NO\n";
			continue;
		}

		queue<char> q;
		q.push(vps[0]);

		for (int j = 1; j < strlen(vps); j++)
		{
			if (vps[j] == ')')
			{
				if(q.size()!=0)
					q.pop();
				else
				{
					flag = 1;
					break;
				}
			}
			if (vps[j] == '(')q.push(vps[j]);
		}
		if (q.size() == 0 && flag == 0)cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}