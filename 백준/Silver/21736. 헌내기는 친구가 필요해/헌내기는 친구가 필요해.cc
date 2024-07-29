#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, start_x, start_y, result = 0;
string s;
vector<vector<char>> campus(600, vector<char>(600));
vector<vector<bool>> visited(600, vector<bool>(600));
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


void bfs() {
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (!(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)) {
				continue;
			}
			if (!visited[next_x][next_y] && campus[next_x][next_y] != 'X') {
				if (campus[next_x][next_y] == 'P') {
					result += 1;
				}
				q.push({ next_x, next_y });
				visited[next_x][next_y] = true;
			}
		}
	}
}

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			campus[i][j] = s[j];
			if (campus[i][j] == 'I') {
				start_x = i;
				start_y = j;
			}
		}
	}
	bfs();
	if (result == 0) {
		cout << "TT" << "\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}