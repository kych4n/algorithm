#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> dp(n + 1);
	dp[1] = true;
	dp[3] = true;
	for (int i = 5; i <= n; i++) {
		dp[i] = !dp[i - 1] || !dp[i - 3];
	}
	if (dp[n]) {
		cout << "SK" << "\n";
	}
	else {
		cout << "CY" << "\n";
	}
	return 0;
}