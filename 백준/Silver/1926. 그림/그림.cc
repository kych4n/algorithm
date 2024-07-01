#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(vector<vector<int>>& paper, vector<vector<bool>>& visited, int x, int y) {
	int area = 0;
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		area += 1;
		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
				if (!visited[new_x][new_y] && paper[new_x][new_y]) {
					visited[new_x][new_y] = true;
					q.push(make_pair(new_x, new_y));
				}
			}
		}
	}
	return area;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	int max_area = 0;
	int number_painting = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] && !visited[i][j]) {
				number_painting += 1;
				max_area = max(max_area, bfs(paper, visited, i, j));
			}
		}
	}
	cout << number_painting << '\n' << max_area << '\n';

	return 0;
}