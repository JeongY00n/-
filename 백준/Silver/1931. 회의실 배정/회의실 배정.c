typedef struct TIME {
	int start;
	int end;
	int size;
}Time;
int compare(const void* a, const void* b) {
	const Time* n1, * n2;
n1 = (const Time*)a;
n2 = (const Time*)b;

if (n1->end != n2->end) {
	if (n1->end < n2->end) {
		return -1;
	}
	else if (n1->end == n2->end) {
		return 0;
	}
	else {
		return 1;
	}
}
else {
	if (n1->start < n2->start) {
		return -1;
	}
	else if (n1->start == n2->start) {
		return 0;
	}
	else {
		return 1;
	}
}
}
void Count(int N, Time* t) {
	
	qsort(t, N, sizeof(Time), compare);
	
	int n = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (n <= t[i].start) {
			n = t[i].end;
			cnt++;
		}
	}
	printf("%d\n", cnt);
}

int main() {
	
	int N = 0; scanf("%d", &N);
	Time* t = (Time*)malloc(N * sizeof(Time));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &t[i].start, &t[i].end);
		t[i].size = t[i].end - t[i].start;
	}
	Count(N, t);
	free(t);
	return 0;
}