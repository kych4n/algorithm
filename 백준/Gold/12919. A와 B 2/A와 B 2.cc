#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
string s, t, temp;
bool possible = false;
int s_length;

void bruteforce(string cur_t) {
	int cur_length = cur_t.length();
	if (cur_length == s_length) {
		if (cur_t == s) {
			possible = true;
		}
		return;
	}
	if (cur_t.back() == 'A') {
		temp = cur_t;
		temp.pop_back();
		bruteforce(temp);
	}
	if (cur_t[0] == 'B') {
		temp = cur_t.substr(1, cur_length);
		reverse(temp.begin(), temp.end());
		bruteforce(temp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> t;
	s_length = s.length();
	bruteforce(t);
	if (possible) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	return 0;
}