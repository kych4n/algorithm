#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, a, b;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> degree(100001);
vector<vector<int>> adj_list(100001);

void topology_sort() {
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";

		int size = adj_list[cur].size();
		for (int i = 0; i < size; i++) {
			int next = adj_list[cur][i];
			degree[next] -= 1;
			if (degree[next] == 0) {
				pq.push(next);
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
		cin >> a >> b;
		degree[b] += 1;
		adj_list[a].push_back(b);
	}

	topology_sort();
	
	return 0;
}
