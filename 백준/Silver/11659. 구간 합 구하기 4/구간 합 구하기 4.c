int main() {
	int N = 0, M = 0; scanf("%d %d", &N, &M);
	int i = 0, j = 0;
	int* num;
	int* sum;
	num = (int*)calloc(N, sizeof(int));
	sum = (int*)calloc(N, sizeof(int));
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
		sum[i] = sum[i - 1] + num[i];
	}
	while (M--)
	{
		scanf("%d %d", &i, &j);
		printf("%lld\n", sum[j]- sum[i - 1]);
	}
	free(num);
	free(sum);
	return 0;
}