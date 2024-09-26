#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int r, c, day = 0;
vector<int> extra_x = { -1, 1, 0, 0 };
vector<int> extra_y = { 0, 0, 1, -1 };
queue<pair<int, int>> waterQ, swanQ;
vector<pair<int, int>> swans;

void melt(vector<vector<char>>& lake) {
	int cur_x, cur_y, new_x, new_y;
	int cur_size = waterQ.size();
	for (int k = 0; k < cur_size; k++) {
		cur_x = waterQ.front().first;
		cur_y = waterQ.front().second;
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			new_x = cur_x + extra_x[i];
			new_y = cur_y + extra_y[i];
			if (new_x < r && new_x >= 0 && new_y < c && new_y >= 0) {
				if (lake[new_x][new_y] == 'X') {
					lake[new_x][new_y] = '.';
					waterQ.push(make_pair(new_x, new_y));
				}
			}
		}
	}
}

bool meet(vector<vector<bool>>& visited, vector<vector<char>>& lake) {
	queue<pair<int, int>> tempQ;
	int cur_x, cur_y, new_x, new_y;
	while (!swanQ.empty()) {
		cur_x = swanQ.front().first;
		cur_y = swanQ.front().second;
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			new_x = cur_x + extra_x[i];
			new_y = cur_y + extra_y[i];
			if (new_x < r && new_x >= 0 && new_y < c && new_y >= 0) {
				if (visited[new_x][new_y]) {
					continue;
				}
				visited[new_x][new_y] = true;
				if (lake[new_x][new_y] == '.') {
					swanQ.push(make_pair(new_x, new_y));
				}
				else if (lake[new_x][new_y] == 'X') {
					tempQ.push(make_pair(new_x, new_y));
				}
				else {
					return true;
				}
			}
		}
	}
	swanQ = tempQ;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	vector<vector<char>> lake(r, vector<char>(c));
	vector<vector<bool>> visited(r, vector<bool>(c, false));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> lake[i][j];
			if (lake[i][j] == 'L') {
				swans.push_back(make_pair(i, j));
			}
			if (lake[i][j] != 'X') {
				waterQ.push(make_pair(i, j));
			}
		}
	}

	swanQ.push(swans[0]);
	visited[swans[0].first][swans[0].second] = true;
	while (true) {
		day++;
		melt(lake);
		if (meet(visited, lake)) {
			cout << day << '\n';
			break;
		}
	}

	return 0;
}