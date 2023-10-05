int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N = 0; scanf("%d", &N);
	int dp[300] = { 0 };
	int num[300] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);		
	}
	dp[0] = num[0];
	dp[1] = MAX(num[0] + num[1], num[1]);
	dp[2] = MAX(num[0] + num[2], num[1] + num[2]);

	for (int i = 3; i < N; i++)
		dp[i] = MAX(dp[i - 2] + num[i], dp[i - 3] + num[i - 1] + num[i]);

	printf("%d", dp[N-1]);
}