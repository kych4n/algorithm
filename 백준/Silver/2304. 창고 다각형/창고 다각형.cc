#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, h, max_h = 0, criteria_number, result = 0;
vector<pair<int, int>> factories;
vector<int> heights(1001);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		factories.push_back({ l, h });
	}
	sort(factories.begin(), factories.end());
	for (int i = 0; i < n; i++) {
		if (factories[i].second > max_h) {
			criteria_number = factories[i].first;
			max_h = factories[i].second;
		}
		heights[factories[i].first] = factories[i].second;
	}

	heights[factories.front().first] = factories.front().second;
	for (int i = factories.front().first + 1; i < criteria_number; i++) {
		heights[i] = max(heights[i - 1], heights[i]);
	}

	heights[factories.back().first] = factories.back().second;
	for (int i = factories.back().first - 1; i > criteria_number; i--) {
		heights[i] = max(heights[i + 1], heights[i]);
	}

	for (int i = factories.front().first; i <= factories.back().first; i++) {
		result += heights[i];
	}
	cout << result << "\n";

	return 0;
}