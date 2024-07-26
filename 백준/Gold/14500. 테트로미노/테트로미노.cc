#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, result = 0;
vector<vector<int>> paper(500, vector<int>(500));
vector<vector<bool>> visited(500, vector<bool>(500));
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


void poli(int x, int y, int count, int sum) {
	if (count == 4) {
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)) {
			continue;
		}
		if (!visited[new_x][new_y]) {
			visited[new_x][new_y] = true;
			poli(new_x, new_y, count + 1, sum + paper[new_x][new_y]);
			visited[new_x][new_y] = false;
		}
	}
}

void poli2(int x, int y) {
	int temp_result = paper[x][y];
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)) {
			continue;
		}
		temp_result += paper[new_x][new_y];
	}
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)) {
			result = max(result, temp_result);
			continue;
		}
		result = max(result, temp_result - paper[new_x][new_y]);
	}
}

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			poli(i, j, 1, paper[i][j]);
			visited[i][j] = false;

			poli2(i, j);
		}
	}
	cout << result << "\n";
	return 0;
}