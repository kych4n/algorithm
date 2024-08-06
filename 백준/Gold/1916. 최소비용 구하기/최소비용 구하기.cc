#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, start, endd, cost, a, b;
vector<vector<pair<int, int>>> adj_list(1001);
vector<int> dist(1001, 1e9 + 7);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra() {
	dist[a] = 0;
	pq.push({ 0, a });
	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (cur_cost > dist[cur_node]) {
			continue;
		}
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> start >> endd >> cost;
		adj_list[start].push_back({ cost, endd });
	}
	cin >> a >> b;
	
	Dijkstra();

	cout << dist[b] << "\n";

	return 0;
}