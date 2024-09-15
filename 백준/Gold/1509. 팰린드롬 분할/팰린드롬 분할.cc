#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int len;
vector<vector<bool>> palindrome(2500, vector<bool>(2500, false));
vector<int> dp(2500, 1e9 + 7);

void make_palindrome() {
	for (int i = 0; i < len; i++) {
		palindrome[i][i] = true;
	}
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == str[i + 1]) {
			palindrome[i][i + 1] = true;
		}
	}
	for (int diff = 2; diff < len; diff++) {
		for (int start = 0; start + diff < len; start++) {
			int end = start + diff;
			if ((str[start] == str[end]) && palindrome[start + 1][end - 1]) {
				palindrome[start][end] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> str;
	len = str.length();

	make_palindrome();

	for (int end = 0; end < len; end++) {
		for (int start = 0; start <= end; start++) {
			if (palindrome[start][end] == true) {
				if (start == 0) {
					dp[end] = 1;
					continue;
				}
				dp[end] = min(dp[end], dp[start - 1] + 1);
			}
		}
	}

	cout << dp[len - 1] << "\n";

	return 0;
}
