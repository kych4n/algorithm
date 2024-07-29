#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> dp(50001);
	for (int i = 1; i <= 50000; i++) {
		dp[i] = i;
	}
	for (int i = 2; i * i <= 50000; i++) {
		for (int j = 0; j + i*i <= 50000; j++) {
			dp[j + i*i] = min(dp[j + i * i], dp[j] + 1);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}