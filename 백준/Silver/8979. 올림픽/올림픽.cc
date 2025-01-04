#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<vector<int>> d(1000, vector<int>(3));

bool compare(int i, int j) {
	if (d[i][0] < d[j][0]) {
		return true;
	}
	else if (d[i][0] == d[j][0]) {
		if (d[i][1] < d[j][1]) {
			return true;
		}
		else if (d[i][1] == d[j][1]) {
			if (d[i][2] < d[j][2]) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, m;
	cin >> n >> k;
	k--;
	for (int i = 0; i < n; i++) {
		cin >> m;
		m--;
		for (int j = 0; j < 3; j++) {
			cin >> d[m][j];
		}
	}
	vector<int> rank(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (compare(i, j)) {
				rank[i] += 1;
			}
		}
	}
	cout << rank[k] << "\n";
	return 0;
}