#include <cstdio>

int main() {
	int sum = 0;
	int input;
	int cnt[1001] = { 0, };
	for (int i = 0; i < 10; i++) {
		scanf("%d", &input);
		sum += input;
		cnt[input] += 1;
	}

	int max = 0;
	int most;
	for (int i = 0; i < 1001; i += 10) {
		if (cnt[i] > max) {
			max = cnt[i];
			most = i;
		}
	}

	printf("%d\n%d", sum / 10, most);
}