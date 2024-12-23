#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m;
vector<vector<int>> map(1000, vector<int>(1000));
vector<vector<pair<int, int> >> dist(1000, vector<pair<int, int>>(1000, { INT32_MAX, INT32_MAX }));
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

class Info {
public:
	int x;
	int y;
	bool possible;
	Info(int x, int y, bool possible) {
		this->x = x;
		this->y = y;
		this->possible = possible;
	}
};

void bfs() {
	queue<Info> q;
	q.push(Info(0, 0, true));
	dist[0][0].first = 1;
	dist[0][0].second = 1;
	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		bool cur_possible = q.front().possible;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
				if (map[new_x][new_y] == 1) {
					if (cur_possible && dist[new_x][new_y].second > dist[cur_x][cur_y].first + 1) {
						dist[new_x][new_y].second = dist[cur_x][cur_y].first + 1;
						q.push(Info(new_x, new_y, false));
					}
				}
				else if (map[new_x][new_y] == 0) {
					if (cur_possible && dist[new_x][new_y].first > dist[cur_x][cur_y].first + 1) {
						dist[new_x][new_y].first = dist[cur_x][cur_y].first + 1;
						q.push(Info(new_x, new_y, cur_possible));
					}
					else if (!cur_possible && dist[new_x][new_y].second > dist[cur_x][cur_y].second + 1) {
						dist[new_x][new_y].second = dist[cur_x][cur_y].second + 1;
						q.push(Info(new_x, new_y, cur_possible));
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	bfs();
	if (dist[n - 1][m - 1].first == INT32_MAX && dist[n - 1][m - 1].second == INT32_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << min(dist[n - 1][m - 1].first, dist[n - 1][m - 1].second) << "\n";
	}
	return 0;
}