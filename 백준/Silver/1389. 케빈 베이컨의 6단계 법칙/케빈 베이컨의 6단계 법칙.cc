#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int MAX = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, MAX));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}

	int min_val = MAX;
	int min_idx = MAX;
	for (int i = 1; i <= n; i++) {
		int temp_val = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				temp_val += dp[i][j];
			}
		}
		if (min_val > temp_val) {
			min_idx = i;
			min_val = temp_val;
		}
	}

	cout << min_idx << '\n';

	return 0;
}