#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int INF = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	vector<long long> dp(101);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 3; i <= 100; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}