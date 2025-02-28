#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
string str;
int result = INT32_MIN;

void dfs(int cur_idx, int res) {
	if (cur_idx >= n) {
		result = max(result, res);
		return;
	}
	if (cur_idx + 2 < n) {
		int a = str[cur_idx] - '0';
		int b = str[cur_idx + 2] - '0';
		char sign = str[cur_idx + 1];
		int temp_result;
		if (sign == '+') {
			temp_result = a + b;
		}
		else if (sign == '-') {
			temp_result = a - b;
		}
		else if (sign == '*') {
			temp_result = a * b;
		}
		if (cur_idx == 0) {
			dfs(4, temp_result);
		}
		else {
			if (str[cur_idx - 1] == '+') {
				dfs(cur_idx + 4, res + temp_result);
			}
			else if (str[cur_idx - 1] == '-') {
				dfs(cur_idx + 4, res - temp_result);
			}
			else if (str[cur_idx - 1] == '*') {
				dfs(cur_idx + 4, res * temp_result);
			}
		}
	}
	int num = str[cur_idx] - '0';
	if (cur_idx == 0) {
		dfs(2, num);
	}
	else {
		if (str[cur_idx - 1]  == '+') {
			dfs(cur_idx + 2, res + num);
		}
		else if (str[cur_idx - 1] == '-') {
			dfs(cur_idx + 2, res - num);
		}
		else if (str[cur_idx - 1] == '*') {
			dfs(cur_idx + 2, res * num);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	cin >> n >> str;
	dfs(0, 0);
	cout << result << "\n";
	return 0;
}