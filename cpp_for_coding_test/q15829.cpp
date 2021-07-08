#include <iostream>
using namespace std;

#define M 1234567891
#define R 31

int main(void)
{
	int L;
	cin >> L;
	char* s = new char[L + 1];
	cin >> s;

	long long answer = 0;
	long long r = 1;
	for (int i = 0; i < L; i++)
	{
		int a = s[i] - 'a' + 1;
		answer += (a * r) % M;
		if (answer >= M)
		{
			answer %= M;
		}

		r *= R;
		if (r >= M)
		{
			r %= M;
		}
	}

	cout << answer << endl;
}