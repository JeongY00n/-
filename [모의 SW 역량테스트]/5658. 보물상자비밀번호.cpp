#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// vector => 정렬
// hash => 문자열의 존재여부 파악
// string => substr

bool cmp(string a, string b) {
	if (a > b)return true;
	if (a < b)return false;

	return false;
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, k;
		
		string str;
		//string num[4];

		unordered_map<string, int> numbers;
		vector<string> v;

		cin >> n >> k;
		cin >> str;
		
		int size = n / 4;
		int start = 0;


		while (start < n) {
			string num;
			if (start + size >= n)
			{
				num = str.substr(start);
				// 문자열 맨앞에서부터 나머지 숫자 저장
				num.append(str.substr(0, start + size - n));

			}
			else
			{
				num = str.substr(start, size);
			}


			start++;

			// 값이 이미 존재하는지 확인
			if (numbers.find(num) != numbers.end()) 
				continue;
			else
			{
				v.push_back(num);
				numbers[num] = 1;
			}

		}
		
		
		int ans = 0;

		sort(v.begin(), v.end(), cmp);

		// 16진수계산 미리 해두기 
		int zinsu[16] = {
			1, 16, 16 * 16, 16 * 16 * 16, 16 * 16 * 16 * 16, 16 * 16 * 16 * 16 * 16, 16 * 16 * 16 * 16 * 16 * 16
		};


		// v의 경우 0 부터 시작하므로 k번째는 k-1번을 의미함
		k--;

		for (int i = 0; i < size; i++)
		{
			if (v[k][i] >= '0' && v[k][i] <= '9')
			{
				ans += int(v[k][i] - '0') * (zinsu[size - 1 - i]);
			}
			else
				ans += int(v[k][i] - 'A' + 10) * (zinsu[size - 1 - i]);


		}


		cout << "#" << tc << " " << ans << "\n";
	}


}