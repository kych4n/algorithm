#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string strA, strB;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> strA >> strB;

	for (int i = 1; i <= strA.length(); i++) {
		for (int j = 1; j <= strB.length(); j++) {
			if (strA[i-1] == strB[j-1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[strA.length()][strB.length()] << "\n";
	return 0;
}