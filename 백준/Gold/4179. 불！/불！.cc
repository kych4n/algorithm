#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0, -1,1 };

bool is_in(int r, int c) {
	return r >= 0 && r < R && c >= 0 && c < C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	vector<vector<char>> raze(R, vector<char>(C));
	vector<vector<int>> min_time(R, vector<int>(C, 1e9 + 7));
	queue<pair<int, int>> q_jh;
	queue<pair<int, int>> q_fire;

	pair<int, int> jh;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> raze[i][j];
			if (raze[i][j] == 'J') {
				raze[i][j] = '.';
				min_time[i][j] = 0;
				q_jh.push({ i,j });
			}
			else if (raze[i][j] == 'F') {
				q_fire.push({i, j});
			}
		}
	}	

	int current_time = 0;

	while (!q_jh.empty() || !q_fire.empty()) {
		current_time++;

		int cnt_fire = q_fire.size();
		for (int i = 0; i < cnt_fire; i++) {
			pair<int, int> cur_fire = q_fire.front();
			q_fire.pop();
			for (int j = 0; j < 4; j++) {
				int next_fire_r = cur_fire.first + dr[j];
				int next_fire_c = cur_fire.second + dc[j];
				if (!is_in(next_fire_r, next_fire_c) || raze[next_fire_r][next_fire_c] != '.') {
					continue;
				}
				raze[next_fire_r][next_fire_c] = 'F';
				q_fire.push({ next_fire_r, next_fire_c });
			}
		}

		/*for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << raze[i][j] << " ";
			}
			cout << "\n";
		}*/

		int cnt_jh = q_jh.size();
		for (int i = 0; i < cnt_jh; i++) {
			pair<int, int> cur_jh = q_jh.front();
			q_jh.pop();
			for (int j = 0; j < 4; j++) {
				int next_jh_r = cur_jh.first + dr[j];
				int next_jh_c = cur_jh.second + dc[j];
				if (!is_in(next_jh_r, next_jh_c)) {
					cout << current_time << "\n";
					return 0;
				}
				else if (raze[next_jh_r][next_jh_c] == '.' && min_time[next_jh_r][next_jh_c] > current_time) {
					min_time[next_jh_r][next_jh_c] = current_time;
					q_jh.push({ next_jh_r, next_jh_c });
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";

	return 0;
}