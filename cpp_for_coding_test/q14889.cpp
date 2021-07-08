#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[21][21];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
		//for (int j = 0; j < n; j++) {
		//	cin >> arr[i][j];
		//}
	}

	int cnt = 0;
	do {
		cnt += 1;
	} while (next_permutation(v.begin(), v.end()));

	int answer = 0;

	cout << cnt << endl;

	return 0;
}