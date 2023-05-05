int main() {
	int A = 0, B = 0;
	scanf("%d %d", &A, &B);
	int cnt = 0;
	while (A < B) {
		cnt++;
		if (B % 10 == 1)
			B /= 10;
		else if (B % 2 == 0)
			B /= 2;
		else
			break;
	}
	if (A != B)
		printf("%d", -1);
	else
		printf("%d", cnt + 1);
}