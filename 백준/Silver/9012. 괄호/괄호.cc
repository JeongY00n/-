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
		char vps[51];
		cin >> vps;
		int close = 0, open = 0, flag = 0;
		for (int j = 0; j < strlen(vps); j++)
		{
			if (vps[j] == '(')open++;
			if (vps[j] == ')')close++;

			if (open < close) {
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if (flag)continue;
		if (open == close)cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}