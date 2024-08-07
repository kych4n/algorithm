#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, n;
vector<int> prices(1000000);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		priority_queue<pair<int, int>> pq;
		long long result = 0;
		for (int j = 0; j < n; j++) {
			cin >> prices[j];
			pq.push({ prices[j], j });
		}

		int max_value;
		for (int j = 0; j < n; j++) {
			while (pq.top().second < j) {
				pq.pop();
			}
			max_value = pq.top().first;
			if (max_value > prices[j]) {
				result += (max_value - prices[j]);
			}
		}
		cout << result << "\n";
	}

	return 0;
}