#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n;
vector<pair<int, int>> dp(41, {0, 0});

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	dp[0].first = 1;
	dp[1].second = 1;
	for (int i=2; i<=40; i++){
		dp[i].first = dp[i-1].first + dp[i-2].first;
		dp[i].second = dp[i-1].second + dp[i-2].second;
	}
	for (int j=0; j<t; j++){
		cin >> n;
		cout << dp[n].first << " " << dp[n].second << "\n";
	}
	return 0;
}