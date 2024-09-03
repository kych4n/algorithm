#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int INF = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b;
	cin >> n;
	vector<vector<bool>> adj_matrix(n + 1, vector<bool>(n + 1));
	vector<vector<int>> floyd(n + 1, vector<int>(n + 1, INF));
	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		floyd[a][b] = 1;
		floyd[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		floyd[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	vector<int> result(n + 1);
	int min_value = INF;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			result[i] = max(result[i], floyd[i][j]);
		}
		if (min_value > result[i]) {
			min_value = result[i];
			count = 1;
		}
		else if (min_value == result[i]) {
			count += 1;
		}
	}
	cout << min_value << " " << count << "\n";
	for (int i = 1; i <= n; i++) {
		if (min_value == result[i]) {
			cout << i << " ";
		}
	}

	return 0;
}