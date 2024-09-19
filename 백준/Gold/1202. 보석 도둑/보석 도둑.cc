#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, m, v, c, p = 0;
long long result = 0;

vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> possible;

int fillBag(int bag_idx) {
	while (p < n && jewel[p].first <= bag[bag_idx]) {
		possible.push(jewel[p++].second);
	}
	if (possible.empty()) {
		return 0;
	}
	else {
		int value = possible.top();
		possible.pop();
		return value;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel.push_back({ m, v });
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	for (int i = 0; i < k; i++) {
		result += fillBag(i);
	}

	cout << result << "\n";
	return 0;
}
