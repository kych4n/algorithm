#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, INF = 1e9+7;
vector<int> dp(1000001, INF);

int main() {
	cin >> n;
	dp[1] = 0;
	for (int i=1; i<n; i++){
		if (i*3 <= 1000000){
			dp[i*3] = min(dp[i*3], dp[i]+1);
		}
		if (i*2 <= 1000000){
			dp[i*2] = min(dp[i*2], dp[i]+1);
		}
		if (i+1 <= 1000000){
			dp[i+1] = min(dp[i+1], dp[i]+1);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}