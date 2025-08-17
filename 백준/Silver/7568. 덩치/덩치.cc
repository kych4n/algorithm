#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, weight, height;
	cin >> n;
	vector<pair<int, int>> info(n);
	vector<int> rank(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> info[i].first >> info[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (info[i].first < info[j].first && info[i].second < info[j].second) {
				rank[i] += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << rank[i] << " ";
	}
	cout << "\n";
	return 0;
}