#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, baby_shark_size = 2, eat_count = 0, baby_shark_x, baby_shark_y, result = 0, min_value, temp_x, temp_y;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

vector<vector<int>> space(20, vector<int>(20));
vector<vector<int>> dist(20, vector<int>(20, 1e9 + 7));

void grow() {
	if (eat_count == baby_shark_size) {
		baby_shark_size += 1;
		eat_count = 0;
	}
}

void bfs() {
	int cur_dist = 0;
	queue<pair<int, int>> q;
	q.push({ baby_shark_x, baby_shark_y });
	dist[baby_shark_x][baby_shark_y] = 0;
	
	while (!q.empty()) {
		int size = q.size();
		cur_dist += 1;
		for (int i = 0; i < size; i++) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int new_x = cur_x + dx[j];
				int new_y = cur_y + dy[j];
				if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
					if (dist[new_x][new_y] > cur_dist) {
						if (space[new_x][new_y] <= baby_shark_size) {
							dist[new_x][new_y] = cur_dist;
							q.push({ new_x, new_y });
						}
					}
					
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				baby_shark_x = i;
				baby_shark_y = j;
				space[i][j] = 0;
			}
		}
	}

	while (true) {
		dist = vector<vector<int>>(20, vector<int>(20, 1e9 + 7));

		bfs();

		min_value = 1e9 + 7;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (baby_shark_size > space[i][j] && space[i][j] > 0) {
					if (dist[i][j] > 0 && min_value > dist[i][j]) {
						baby_shark_x = i;
						baby_shark_y = j;
						min_value = dist[i][j];
					}
				}
			}
		}

		if (min_value == 1e9 + 7) {
			break;
		}

		eat_count += 1;
		space[baby_shark_x][baby_shark_y] = 0;
		grow();
		result += min_value;
	}

	cout << result << "\n";
	

	return 0;
}