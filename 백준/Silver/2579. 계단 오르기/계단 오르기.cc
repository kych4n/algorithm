#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int n;
vector<int> stage(301);
vector<vector<int>> dp(301, vector<int>(3));

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> stage[i];
	}

	dp[1][1] = stage[1];	// 시작점은 계단으로 포함시키지 않기 때문에 첫번째 계단까지 연속 횟수는 첫번째 계단만을 고려한 1
	dp[1][0] = stage[1];
	for (int i=2; i<=n; i++){
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stage[i];
		dp[i][2] = dp[i-1][1] + stage[i];
		dp[i][0] = max(dp[i][1], dp[i][2]);
	}

	cout << dp[n][0] << "\n";

	return 0;
}