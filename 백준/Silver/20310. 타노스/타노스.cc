#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string s;
int zero_count = 0;
int one_count = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			one_count += 1;
		}
		else {
			zero_count += 1;
		}
	}
	one_count /= 2;
	zero_count /= 2;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			if (one_count > 0) {
				s[i] = 'X';
				one_count -= 1;
			}
			else {
				break;
			}
		}
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			if (zero_count > 0) {
				s[i] = 'X';
				zero_count -= 1;
			}
			else {
				break;
			}
		}
	}
	string result = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'X') {
			result += s[i];
		}
	}
	cout << result << "\n";
	return 0;
}