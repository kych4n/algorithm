#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, number, k, result;
vector<int> triangle(1, -1);
vector<int> dp(500 * 501 / 2);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> number;
			triangle.push_back(number);
		}
	}

	k = 1;
	dp[1] = triangle[1];
	result = dp[1];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			dp[k + i] = max(dp[k + i], dp[k] + triangle[k + i]);
			dp[k + i + 1] = max(dp[k + i + 1], dp[k] + triangle[k + i + 1]);
			result = max(max(result, dp[k + i]), dp[k + i + 1]);
			k++;
		}
	}

	cout << result << "\n";
	
	return 0;
}