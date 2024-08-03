#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj_list(1001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> to_x(1001, 1e9 + 7);
vector<int> from_x(1001, 1e9 + 7);
int n, m, x, start, endd, cost, max_cost = 0;

void dijkstra_to_x(int start_x) {
	vector<int> temp_dist(1001, 1e9 + 7);
	temp_dist[start_x] = 0;
	pq.push({ 0, start_x });
	while (!pq.empty()) {
		int cur_x = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < adj_list[cur_x].size(); i++) {
			int next_x = adj_list[cur_x][i].second;
			int next_cost = cur_cost + adj_list[cur_x][i].first;
			if (next_x == x) {
				to_x[start_x] = min(to_x[start_x], next_cost);
			}
			else {
				if (temp_dist[next_x] > next_cost) {
					temp_dist[next_x] = next_cost;
					pq.push({ next_cost, next_x });
				}
				
			}
		}
	}
}

void dijkstra_from_x(int start_x) {
	from_x[start_x] = 0;
	pq.push({ 0, start_x });
	while (!pq.empty()) {
		int cur_x = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < adj_list[cur_x].size(); i++) {
			int next_x = adj_list[cur_x][i].second;
			int next_cost = cur_cost + adj_list[cur_x][i].first;
			if (from_x[next_x] > next_cost) {
				from_x[next_x] = next_cost;
				pq.push({ next_cost, next_x });
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> start >> endd >> cost;
		adj_list[start].push_back({ cost, endd });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra_to_x(i);
	}
	dijkstra_from_x(x);

	for (int i = 1; i <= n; i++) {
		max_cost = max(max_cost, to_x[i] + from_x[i]);
	}
	cout << max_cost << "\n";

	return 0;
}