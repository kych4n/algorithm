#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long n, m, a, b, c;
vector<long long> dist(501, 1e9 + 7);
vector<vector<int>> edges(6000, vector<int>(3));

bool bf(int start) {
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cur_node = edges[j][0];
			int next_node = edges[j][1];
			int cost = edges[j][2];
			if (dist[cur_node] != 1e9+7 && dist[next_node] > dist[cur_node] + cost) {
				dist[next_node] = dist[cur_node] + cost;
				if (i == n - 1) {
					return true;
				}
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> edges[i][j];
		}
	}
	
	bool result = bf(1);
	if (result) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == 1e9 + 7) {
				cout << -1 << "\n";
			}
			else {
				cout << dist[i] << "\n";
			}
		}
	}

	return 0;
}