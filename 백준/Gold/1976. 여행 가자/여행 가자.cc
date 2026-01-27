#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> adj_list;
vector<int> plan;
vector<int> parent;

int find_parent(int x) {
	if (x != parent[x]) {
		return find_parent(parent[x]);
	}
	return parent[x];
}

void union_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	adj_list.resize(N, vector<int>(N));
	parent.resize(N);
	plan.resize(M);
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		for (int j = 0; j < N; j++) {
			cin >> adj_list[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> plan[i];
		plan[i]--;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adj_list[i][j] && parent[i] != parent[j]) {
				union_parent(i, j);
			}
		}
	}

	for (int i = 0; i < M - 1; i++) {
		int start = plan[i];
		int end = plan[i + 1];
		if (find_parent(start) != find_parent(end)) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
	return 0;
}