#include <bits/stdc++.h>
using namespace std;

int main() {
	int answer = 0;

	int n;
	cin >> n;

	vector<int> v0;
	vector<int> v1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v0.push_back(x);
		v1.push_back(x);
	}

	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());

	for (int i = 0; i < v0.size(); i++) {
		int key = v0[i];
		answer = lower_bound(v1.begin(), v1.end(), key) - v1.begin();
		cout << answer << " ";
	}
	cout << endl;
	return 0;
}