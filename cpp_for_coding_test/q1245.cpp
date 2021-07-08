#include <bits/stdc++.h>
#define MAXN 10
using namespace std;
int T;
int N;
double answer;
int x[MAXN];
int m[MAXN];
double ERR = 1e-12;

pair<double, double> calForce(double mid) {
	double fL = 0, fR = 0;

	int idxL = 0, idxR = 0;
	for (int i = 0; i < N; i++) {
		if (x[i] > mid) {
			idxL = i - 1;
			idxR = i;
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		double d = x[i] - mid;
		if (i <= idxL)
			fL += (double)m[i] / (d * d);
		else
			fR += (double)m[i] / (d * d);
	}

	return { fL, fR };
}

double binarySearch(double start, double end) {
	double mid = 0.0;
	while (end - start >= ERR) {
		mid = (start + end) / 2;
		pair<double, double> f = calForce(mid);
		double fL = f.first;
		double fR = f.second;
		if (fL < fR) {
			end = mid - ERR;
		}
		else {
			start = mid + ERR;
		}
	}
	return mid;
}

int main(int argc, char** argv)
{
	cout << fixed;
	cout.precision(10);

	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < N - 1; i++) {
			answer = binarySearch(x[i], x[i + 1]);
			cout << answer << " ";
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}