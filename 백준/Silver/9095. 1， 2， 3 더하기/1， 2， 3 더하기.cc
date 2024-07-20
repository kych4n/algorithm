#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> dp(11);

int main(void)
{	
	dp[0] = 1;
	for (int i = 1; i < 11; i++) {
		if (i - 1 >= 0) {
			dp[i] += dp[i - 1];
		}
		if (i - 2 >= 0) {
			dp[i] += dp[i - 2];
		}
		if (i - 3 >= 0) {
			dp[i] += dp[i - 3];
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}