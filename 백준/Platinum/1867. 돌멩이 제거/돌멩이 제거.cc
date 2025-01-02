#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

int n, k, row, col;
bool visited[501];
vector<int> bp(501);
vector<vector<int>> grid(501);

bool dfs(int row) {
	if (visited[row]) {
		return false;
	}
	visited[row] = true;
	for (int i = 0; i < grid[row].size(); i++) {
		int cur_col = grid[row][i];
		if (bp[cur_col] == 0 || dfs(bp[cur_col])) {
			bp[cur_col] = row;
			return true;
		}
	}
	return false;
}

int main(void) {
	int answer = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		grid[row].push_back(col);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, n + 1);
		if (dfs(i)) {
			answer += 1;
		}
	}
	cout << answer << "\n";

	return 0;
}