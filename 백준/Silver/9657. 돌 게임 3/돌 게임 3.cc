#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<bool> dp(1001);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;
	dp[4] = true;
	for (int i = 5; i <= n; i++) {
		dp[i] = !dp[i - 1] || !dp[i - 3] || !dp[i - 4];
	}
	if (dp[n]) {
		cout << "SK" << "\n";
	}
	else {
		cout << "CY" << "\n";
	}
	return 0;
}