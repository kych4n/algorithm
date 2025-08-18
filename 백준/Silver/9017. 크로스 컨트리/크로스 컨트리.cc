#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int t, n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int u = 0; u < t; u++) {
		cin >> n;
		vector<int> orders(1000);
		vector<int> counts(201);
		for (int i = 0; i < n; i++) {
			cin >> orders[i];
			counts[orders[i]] += 1;
		}
		vector<int> new_orders;
		for (int i = 0; i < n; i++) {
			if (counts[orders[i]] < 6) {
				continue;
			}
			new_orders.push_back(orders[i]);
		}
		vector<vector<int>> scores(1001);
		for (int i = 0; i < new_orders.size(); i++) {
			scores[new_orders[i]].push_back(i + 1);
		}
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> results;
		for (int i = 1; i <= n; i++) {
			if (scores[i].empty()) {
				continue;
			}
			int sum = accumulate(scores[i].begin(), scores[i].end() - 2, 0);
			results.push({ sum, scores[i][4], i});
		}
		cout << results.top()[2] << "\n";
	}

	return 0;
}