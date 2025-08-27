#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

unordered_map<int, string> upperBound_to_title;
vector<int> upperBounds;
int n, m, upperBound, power;
string title;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> title >> upperBound;
		if (upperBound_to_title.find(upperBound) == upperBound_to_title.end()) {
			upperBound_to_title[upperBound] = title;
			upperBounds.push_back(upperBound);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> power;
		auto it = lower_bound(upperBounds.begin(), upperBounds.end(), power);
		if (it != upperBounds.end()) {
			int idx = it - upperBounds.begin();
			cout << upperBound_to_title[upperBounds[idx]] << "\n";
		}
	}
	return 0;
}