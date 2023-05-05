void Sum(int N, int* n) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (n[i] > n[j])
			{
				int num = n[j];
				n[j] = n[i];
				n[i] = num;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		sum += n[i] * (N - i); ///
	}

	printf("%d", sum);
}
int main() {
	int N = 0, * n;
	scanf("%d", &N);
	n = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		scanf("%d", &n[i]);
	Sum(N, n);
}