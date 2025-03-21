#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n, result = 0;
vector<vector<int>> house(16, vector<int>(16));
vector<vector<vector<int>>> dp(16, vector<vector<int>>(16, vector<int>(3)));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}
	dp[0][1][0] = 1;
	for (int i = 2; i < n; i++) {
		if (!house[0][i]) {
			dp[0][i][0] = 1;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (!house[i][j]) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
				if (!house[i - 1][j] && !house[i][j - 1]) {
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
		}
	}
	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << "\n";
	return 0;
}