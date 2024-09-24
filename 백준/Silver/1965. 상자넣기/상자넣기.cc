#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> boxes(1000);
vector<int> dp(1000, 1);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> boxes[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (boxes[i] < boxes[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}
	cout << result << "\n";
	return 0;
}
