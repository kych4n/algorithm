#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0 ,-1,1 };

int n, m, target_x, target_y;
vector<vector<int>> map(1000, vector<int>(1000));
vector<vector<int>> save(1000, vector<int>(1000, 1e9 + 7));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				target_x = i;
				target_y = j;
				save[i][j] = 0;
			}
			else if (map[i][j] == 0) {
				save[i][j] = 0;
			}
		}
	}
	queue<pair<int, int>> q;
	q.push({ target_x, target_y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
				if (save[new_x][new_y] > save[cur_x][cur_y] + 1) {
					save[new_x][new_y] = save[cur_x][cur_y] + 1;
					q.push({ new_x, new_y });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (save[i][j] == 1e9 + 7) {
				cout << -1 << " ";
			}
			else {
				cout << save[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}