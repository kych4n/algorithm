#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, m, v, a, b;
vector<vector<int>> adj_list(1001);
vector<bool> visited(1001);

void dfs(int cur_point){
	visited[cur_point] = true;
	cout << cur_point << " ";
	for (int i=0; i<adj_list[cur_point].size(); i++){
		int new_point = adj_list[cur_point][i];
		if (!visited[new_point]){
			dfs(new_point);
		}
	}	
}

void bfs(int start_point){
	queue<int> q;
	q.push(start_point);
	visited[start_point] = true;
	cout << start_point << " ";
	while (!q.empty()){
		int cur_point = q.front();
		q.pop();
		for (int i=0; i<adj_list[cur_point].size(); i++){
			int new_point = adj_list[cur_point][i];
			if (!visited[new_point]){
				visited[new_point] = true;
				q.push(new_point);
				cout << new_point << " ";
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> v;
	for (int i=0; i<m; i++){
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	for (int i=1; i<=n; i++){
		sort(adj_list[i].begin(), adj_list[i].end());
	}
	dfs(v);
	visited = vector<bool>(1001);
	cout << "\n";
	bfs(v);
	return 0;
}