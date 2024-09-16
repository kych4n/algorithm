#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, MOD = 1e9;
long long dp[1 << 10][101][10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	if (n <= 9) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= 9; i++) {
		dp[1 << i][1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				if (j == 0) {
					dp[k | (1 << j)][i][j] += dp[k][i - 1][j + 1] % (int)10e8;
				}
				else if (j == 9) {
					dp[k | (1 << j)][i][j] += dp[k][i - 1][j - 1] % (int)10e8;
				}
				else {
					dp[k | (1 << j)][i][j] += (dp[k][i - 1][j - 1] + dp[k][i - 1][j + 1]) % (int)10e8;
				}
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[(1 << 10) - 1][n][i]) % (int)10e8;
	}

	cout << answer << "\n";

	return 0;
}
