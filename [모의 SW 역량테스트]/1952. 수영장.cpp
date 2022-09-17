#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;


// day, month, month3, year
int day, month, month3, year;
int months[13];
vector<int> v;
int mini = year;  //연간 이용(year)
void dfs(int now, int sum, int cnt)
{
	int de = 1;
	if (now == v.size())
	{
		// 10 100 50 300 
		// 0 0 0 0 0 0 0 0 6 2 7 8 이러한 경우를 고려해주어야한다
		// 3개월(6,2,7) + 3개월(8) = 100 이 가장 저렴
		if (cnt > 0)
		{
			if (mini > sum + month3)
				mini = sum + month3;
		}
		else
		{
			if (mini > sum)
				mini = sum;
		}

		return;
	}

	if (cnt == 0)
	{
		dfs(now + 1, sum + (months[v[now]] * day), cnt);

		dfs(now + 1, sum + month, cnt);

		dfs(now + 1, sum, cnt + 1);
	}
	else
	{
		// 연속된 달이 아닌 경우 return
		if (v[now] - v[now - 1] != 1) return;

		// cnt를 3으로 하면 안된다!!!!!!!!!!!!!!!!!
		// cnt=> 0, 1, 2로 3개라고 봐야한다
		// (1, 0, 1) (2, 0, 2) (3, 0, 3)으로 보게 된다면 v[3]에 대해서는 계산을 해줄 수 없다
		if (cnt == 2)
			dfs(now + 1, sum + month3, 0);
		else
			dfs(now + 1, sum, cnt + 1);
	}


}



int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		v.clear();

		cin >> day >> month >> month3 >> year;

		mini = year;  // 연간 이용의 경우(year)

		for (int i = 1; i <= 12; i++)
		{
			cin >> months[i];
			if (months[i] != 0)
				v.push_back(i);
		}

		dfs(0, 0, 0);

		cout << "#" << tc << " " << mini << "\n";

	}




	return 0;
}