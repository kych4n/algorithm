#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;
vector<vector<int>> stickers(2, vector<int>(100000));
vector<vector<int>> dp(100000, vector<int>(3));

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> stickers[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> stickers[1][i];
		}

		dp[0][0] = stickers[0][0];
		dp[0][1] = stickers[1][0];
		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + stickers[0][i];
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + stickers[1][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
		}

		int result = 0;
		for (int i = 0; i < 3; i++) {
			result = max(result, dp[n - 1][i]);
		}
		cout << result << "\n";

	}
	
	return 0;
}