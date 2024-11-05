#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> point(n);
	for (int i = 0; i < n; i++) {
		cin >> point[i].first >> point[i].second;
	}
	sort(point.begin(), point.end());

	long long result = 0;
	int start = point[0].first;
	int end = point[0].second;

	for (int i = 1; i < n; i++) {
		int x = point[i].first;
		int y = point[i].second;
		if (end >= x && end < y) {
			end = y;
		}
		else if (end < x) {
			result += end - start;
			start = x;
			end = y;
		}
	}
	result += end - start;
	cout << result << "\n";
	return 0;
}