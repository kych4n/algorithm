#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, m, a, b, result=0;
vector<vector<int>> adj_list(101);
vector<bool> visited(101);
queue<int> q;

void bfs(){
	visited[1] = true;
	q.push(1);
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i=0; i<adj_list[x].size(); i++){
			int y = adj_list[x][i];
			if (!visited[y]){
				q.push(y);
				visited[y] = true;
				result += 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<m; i++){
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	bfs();
	cout << result << "\n";

	return 0;
}