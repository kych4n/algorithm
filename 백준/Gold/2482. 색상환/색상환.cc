#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int MOD = 1e9 + 3;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			if (i / j == 2 && i % j == 0) {
				dp[i][j] = 2;
			}
			else if (i / 2 < j) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
			}
		}
	}
	cout << dp[n][k] << "\n";
	return 0;
}