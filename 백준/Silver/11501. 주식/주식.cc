#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, n;
vector<int> stock(1000000);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;

	for (int u = 1; u <= t; u++) {
		long long result = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> stock[i];
		}

		int max_value = stock[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			max_value = max(max_value, stock[i]);
			result += max_value - stock[i];
		}

		cout << result << "\n";
	}
	return 0;
}
