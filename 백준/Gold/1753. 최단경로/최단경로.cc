#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e, k, u, v, w, result = 0;
vector<vector<pair<int, int>>> adj_list(20001);
vector<int> dist(20001, 1e9 + 7);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra() {
	dist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj_list[cur_node].size(); i++) {
			int next_node = adj_list[cur_node][i].second;
			int next_cost = cur_cost + adj_list[cur_node][i].first;
			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push({ next_cost, next_node });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> e >> k;
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		adj_list[u].push_back({ w, v });
	}

	Dijkstra();

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 1e9 + 7) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}