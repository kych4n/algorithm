#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> adj_list;
vector<int> plan;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	adj_list.resize(N, vector<int>(N));
	plan.resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj_list[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		adj_list[i][i] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> plan[i];
		plan[i]--;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || adj_list[i][j]) continue;
				adj_list[i][j] = max(adj_list[i][j], adj_list[i][k] * adj_list[k][j]);
			}
		}
	}
	
	for (int i = 0; i < M - 1; i++) {
		int start = plan[i];
		int end = plan[i + 1];
		if (!adj_list[start][end]) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
	return 0;
}