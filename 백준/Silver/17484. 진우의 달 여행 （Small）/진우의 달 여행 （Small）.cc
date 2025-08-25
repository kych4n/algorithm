#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m, result = 1e9 + 7;
vector<vector<int>> costs(6, vector<int>(6));
vector<vector<vector<int>>> dp(6, vector<vector<int>>(6, vector<int>(3, 1e9 + 7)));
int dx[] = { -1,0,1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> costs[i][j];
		}
	}
	for (int i = 1; i < m - 1; i++) {
		for (int j = 0; j < 3; j++) {
			dp[0][i][j] = costs[0][i];
		}
	}
	dp[0][0][0] = costs[0][0];
	dp[0][0][1] = costs[0][0];
	dp[0][m - 1][1] = costs[0][m - 1];
	dp[0][m - 1][2] = costs[0][m - 1];

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (k == l) {
						continue;
					}
					int new_x = j + dx[l];
					if (new_x >= 0 && new_x < m) {
						dp[i + 1][new_x][l] = min(dp[i + 1][new_x][l], dp[i][j][k] + costs[i + 1][new_x]);
					}
				}
				
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			result = min(result, dp[n - 1][i][j]);
		}
	}
	cout << result << "\n";
	return 0;
}