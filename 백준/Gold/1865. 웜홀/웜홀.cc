#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int tc, n, m, w, s, e, t;
vector<vector<int>> edges;
vector<long long> dist(501);

bool bf(int start) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * m + w; j++) {
			int cur_node = edges[j][0];
			int next_node = edges[j][1];
			int cost = edges[j][2];
			if (dist[next_node] > dist[cur_node] + cost) {
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
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		bool is_possible = false;
		edges.clear();
		cin >> n >> m >> w;
		for (int j = 0; j < m; j++) {
			cin >> s >> e >> t;
			edges.push_back({ s, e, t });
			edges.push_back({ e, s, t });
		}
		for (int j = 0; j < w; j++) {
			cin >> s >> e >> t;
			edges.push_back({ s, e, -t });

		}
		
		if (bf(1)) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}

	return 0;
}