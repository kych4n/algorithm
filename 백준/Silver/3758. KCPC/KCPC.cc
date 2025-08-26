#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int T, n, k, t, m, i, j, s;

bool compare(const vector<int>& a, const vector<int>& b) {
	int sum_a = accumulate(a.begin() + 1, a.begin() + k + 1, 0);
	int sum_b = accumulate(b.begin() + 1, b.begin() + k + 1, 0);
	if (sum_a > sum_b) {
		return true;
	}
	else if (sum_a == sum_b) {
		if (a[k + 1] < b[k + 1]) {
			return true;
		}
		else if (a[k + 1] == b[k + 1]) {
			if (a[k + 2] < b[k + 2]) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int x = 0; x < T; x++) {
		cin >> n >> k >> t >> m;
		int ranking = 1;
		vector<vector<int>> info(n + 1, vector<int>(k + 1 + 2));	// 제출 횟수, 마지막 제출 시간
		for (int y = 1; y <= m; y++) {
			cin >> i >> j >> s;
			info[i][j] = max(info[i][j], s);
			info[i][k + 1] += 1;
			info[i][k + 2] = y;
		}

		for (int y = 1; y <= n; y++) {
			if (y != t && !compare(info[t], info[y])) {
				ranking += 1;
			}
		}
		cout << ranking << "\n";
	}
	return 0;
}