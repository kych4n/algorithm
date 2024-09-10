#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, finish_day, result;
vector<pair<int, int>> info(1500001);
vector<int> dp(1500001);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> info[i].first >> info[i].second;

		dp[i] = max(dp[i], dp[i - 1]);

		finish_day = i + info[i].first - 1;
		if (finish_day > n) {
			continue;
		}
		dp[finish_day] = max(dp[finish_day], dp[i - 1] + info[i].second);

;	}

	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i]);
	}

	cout << result << "\n";
	return 0;
}
