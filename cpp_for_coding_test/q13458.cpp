#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int* number = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}

	int b, c;
	scanf("%d", &b);
	scanf("%d", &c);

	long long answer = 0;
	for (int i = 0; i < n; i++) {
		number[i] -= b;
		answer += 1;
		if (number[i] > 0) {
			int q = number[i] / c;
			int r = number[i] % c;
			if (r == 0)
				answer += q;
			else
				answer += q + 1;
		}
	}

	printf("%lld\n", answer);

	delete[] number;
	return 0;
}