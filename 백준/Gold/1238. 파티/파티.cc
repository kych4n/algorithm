#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int INF = 1e9 + 7;

void Dijkstra(vector<vector<pair<int, int>>> info, vector<int>& dist, int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	dist[start] = 0;
	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur_to = pq.top().second;
		pq.pop();
		for (int i = 0; i < info[cur_to].size(); i++) {
			int new_cost = info[cur_to][i].first;
			int new_to = info[cur_to][i].second;
			if (dist[new_to] > cur_cost + new_cost) {
				dist[new_to] = cur_cost + new_cost;
				pq.push({ dist[new_to], new_to });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x, from, to, cost;
	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> info(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		info[from].push_back(make_pair(cost, to));
	}

	vector<int> to_x(n + 1, INF);
	for (int i = 1; i <= n; i++) {
		vector<int> dist(n + 1, INF);
		Dijkstra(info, dist, i);
		to_x[i] = dist[x];
	}
	vector<int> from_x(n + 1, INF);
	Dijkstra(info, from_x, x);

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, to_x[i] + from_x[i]);
	}
	cout << result << '\n';

	return 0;
}