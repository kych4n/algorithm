#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, result = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> paper(100, vector<int>(100));
vector<vector<int>> visited(100, vector<int>(100));

void bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;
	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (true) {
		while (!q.empty()) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int new_x = cur_x + dx[i];
				int new_y = cur_y + dy[i];
				if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)) {
					continue;
				}
				if (paper[new_x][new_y] == 0 && visited[new_x][new_y] == 0) {
					visited[new_x][new_y] += 1;
					q.push({ new_x, new_y });
				}
				else if (paper[new_x][new_y] == 1) {
					visited[new_x][new_y] += 1;
					if (visited[new_x][new_y] == 2) {
						next_q.push({ new_x, new_y });
					}
				}
			}
		}
		if (next_q.empty()) {
			break;
		}
		else {
			result += 1;
		}

		while (!next_q.empty()) {
			int new_x = next_q.front().first;
			int new_y = next_q.front().second;
			q.push(next_q.front());
			next_q.pop();
			paper[new_x][new_y] = 0;
		}
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

	bfs();

	cout << result << "\n";
	
	return 0;
}