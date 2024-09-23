#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<int> degree(32001);
vector<vector<int>> graph(32001);

void topology_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur_x = q.front();
		q.pop();
		cout << cur_x << " ";
		int size = graph[cur_x].size();
		for (int i = 0; i < size; i++) {
			int next_x = graph[cur_x][i];
			degree[next_x] -= 1;
			if (degree[next_x] == 0) {
				q.push(next_x);
;			}

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
		graph[a].push_back(b);
	}

	topology_sort();

	return 0;
}
