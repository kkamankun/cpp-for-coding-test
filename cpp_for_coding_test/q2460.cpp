#include <iostream>
using namespace std;

int main() {

	int in[10];
	int out[10];
	for (int i = 0; i < 10; i++) {
		cin >> out[i] >> in[i];
	}

	int answer = 0;
	int max = 0;
	
	for (int i = 0; i < 10; i++) {
		answer -= out[i];
		answer += in[i];
		if (answer > max) {
			max = answer;
		}
	}

	cout << max << endl;

	return 0;
}