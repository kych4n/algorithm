#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x;
vector<int> bridges;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		bridges.push_back(x);
	}
	int min_height = max(bridges[0], n - bridges.back());
	for (int i = 0; i < m - 1; i++) {
		if (min_height * 2 < bridges[i + 1] - bridges[i]) {
			min_height = (bridges[i + 1] - bridges[i]) / 2;
			if ((bridges[i + 1] - bridges[i]) % 2 != 0) {
				min_height += 1;
			}
		}
	}
	cout << min_height << "\n";
	return 0;
}