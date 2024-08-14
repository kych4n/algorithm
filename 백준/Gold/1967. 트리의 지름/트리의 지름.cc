#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, start, endd, cost, max_node, max_value = 0;
vector<vector<pair<int, int>>> adj_list(10001);
vector<bool> visited(10001);

void dfs(int cur_node, int cur_cost) {
	if (cur_cost > max_value) {
		max_value = cur_cost;
		max_node = cur_node;
	}

	int size = adj_list[cur_node].size();
	for (int i = 0; i < size; i++) {
		int next_node = adj_list[cur_node][i].first;
		int next_cost = cur_cost + adj_list[cur_node][i].second;
		if (!visited[next_node]){
			visited[next_node] = true;
			dfs(next_node, next_cost);
			visited[next_node] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> start >> endd >> cost;
		adj_list[start].push_back({ endd, cost });
		adj_list[endd].push_back({ start, cost });
	}
	
	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;

	visited[max_node] = true;
	dfs(max_node, 0);
	visited[max_node] = false;

	cout << max_value << "\n";
	
	return 0;
}