#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v, start, endd, cost, max_node, result = 0;
vector<vector<pair<int, int>>> adj_list(100001);
vector<bool> visited(100001,false);

void dfs(int cur_node, int cur_cost) {
	if (result < cur_cost) {
		result = cur_cost;
		max_node = cur_node;
	}

	for (int i = 0; i < adj_list[cur_node].size(); i++) {
		int next_node = adj_list[cur_node][i].first;
		int next_cost = adj_list[cur_node][i].second;
		if (!visited[next_node]) {
			visited[next_node] = true;
			dfs(next_node, cur_cost + next_cost);
			visited[next_node] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> start;
		while (true) {
			cin >> endd;
			if (endd == -1) {
				break;
			}
			cin >> cost;
			adj_list[start].push_back({ endd, cost });
		}
	}

	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;

	visited[max_node] = true;
	dfs(max_node, 0);
	visited[max_node] = false;
	
	cout << result << "\n";

	return 0;
}