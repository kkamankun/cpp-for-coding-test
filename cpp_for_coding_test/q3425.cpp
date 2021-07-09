#include<bits/stdc++.h>
using namespace std;

int N, val;
string cmd;

int main() {
		
	while (true) {
		vector<string> cmds;
		vector<int> vals;

		while (true) {
			getline(cin, cmd);
			if (cmd[0] == 'Q')
				return 0;
			else if (cmd[0] == 'E')
				break;
			else if (cmd == "\n")
				continue;
			cmds.push_back(cmd);
		}

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> val;
			vals.push_back(val);
		}

		for (int i = 0; i < N; i++) {
			stack<int> st;
			int val = vals[i];
			st.push(val);
			bool err = false;
			for (int j = 0; j < (signed)cmds.size(); j++) {
				string cmd = cmds[j];
				if (cmd[0] == 'N') {
					string num = "";
					for (int i = 4; i < (signed)cmd.length(); i++) {
						num += cmd[i];
					}
					st.push(stoi(num));
				}
				else if (cmd[0] == 'P') {
					if (st.size() == 0) {
						err = true;
						break;
					}
					else
						st.pop();
				}
				else if (cmd[0] == 'I') {
					if (st.size() == 0) {
						err = true;
						break;
					}
					else {
						int top = st.top();
						st.pop();
						st.push(-top);
					}
				}
				else if (cmd[0] == 'D') {
					if (cmd[1] == 'U') {
						if (st.size() == 0) {
							err = true;
							break;
						}
						int top = st.top();
						st.push(top);
					}
					else if (cmd[1] == 'I') {
						if (st.size() < 2) {
							err = true;
							break;
						}
						int top1 = st.top();
						st.pop();
						int top2 = st.top();
						st.pop();
						if (top1 == 0) {
							err = true;
							break;
						}
						else
							st.push(top2 / top1);
					}
				}
				else if (cmd[0] == 'S') {
					if (cmd[1] == 'W') {
						if (st.size() < 2) {
							err = true;
							break;
						}
						int top1 = st.top();
						st.pop();
						int top2 = st.top();
						st.pop();
						st.push(top1);
						st.push(top2);
					}
					else if (cmd[1] == 'U') {
						if (st.size() < 2) {
							err = true;
							break;
						}
						long long top1 = st.top();
						st.pop();
						long long top2 = st.top();
						st.pop();
						long long result = top2 - top1;
						if (abs(result) > 1e9) {
							err = true;
							break;
						}
						else {
							st.push((int)result);
						}
					}
				}
				else if (cmd[0] == 'A') {
					if (st.size() < 2) {
						err = true;
						break;
					}
					long long top1 = st.top();
					st.pop();
					long long top2 = st.top();
					st.pop();
					long long result = top2 + top1;
					if (result > 1e9) {
						err = true;
						break;
					}
					st.push((int)result);
				}
				else if (cmd[0] == 'M') {
					if (cmd[1] == 'U') {
						if (st.size() < 2) {
							err = true;
							break;
						}
						long long top1 = st.top();
						st.pop();
						long long top2 = st.top();
						st.pop();
						long long result = top2 * top1;
						if (result > 1e9) {
							err = true;
							break;
						}
						else {
							st.push((int)result);
						}
					}
					else if (cmd[1] == 'O') {
						if (st.size() < 2) {
							err = true;
							break;
						}
						int top1 = st.top();
						st.pop();
						int top2 = st.top();
						st.pop();
						if (top1 == 0) {
							err = true;
							break;
						}
						int result = top2 % top1;
						st.push(result);
					}
				}
			}

			if (st.size() != 1) {
				cout << "ERROR" << endl;
			}
			else if (err) {
				cout << "ERROR" << endl;
			}
			else {
				cout << st.top() << endl;
			}
		}
		cout << endl;
	}
	return 0;
}