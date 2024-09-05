#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int r, c, t, spread_amount, result = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> before_spread(50, vector<int>(50));
vector<vector<int>> after_spread(50, vector<int>(50));
vector<int> vacuum_row;

void spread() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			after_spread[i][j] += before_spread[i][j];
			if (before_spread[i][j] == -1) {
				continue;
			}
			spread_amount = before_spread[i][j] / 5;
			for (int k = 0; k < 4; k++) {
				int new_x = i + dx[k];
				int new_y = j + dy[k];
				if ((new_x >= 0 && new_x < r && new_y >= 0 && new_y < c) && before_spread[new_x][new_y] != -1) {
					after_spread[i][j] -= spread_amount;
					after_spread[new_x][new_y] += spread_amount;
				}
			}
			
		}
	}
	before_spread = after_spread;
	after_spread = vector<vector<int>>(50, vector<int>(50));
}

void clockwise() {
	for (int i = vacuum_row[1] + 1; i < r - 1; i++) {
		before_spread[i][0] = before_spread[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		before_spread[r - 1][i] = before_spread[r - 1][i + 1];
	}
	for (int i = r - 1; i > vacuum_row[1]; i--) {
		before_spread[i][c - 1] = before_spread[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		before_spread[vacuum_row[1]][i] = before_spread[vacuum_row[1]][i - 1];
	}

	before_spread[vacuum_row[1]][1] = 0;
}

void anti_clockwise() {
	for (int i = vacuum_row[0] - 1; i > 0; i--) {
		before_spread[i][0] = before_spread[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		before_spread[0][i] = before_spread[0][i + 1];
	}
	for (int i = 0; i < vacuum_row[0]; i++) {
		before_spread[i][c - 1] = before_spread[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		before_spread[vacuum_row[0]][i] = before_spread[vacuum_row[0]][i - 1];
	}
	before_spread[vacuum_row[0]][1] = 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> before_spread[i][j];
			if (before_spread[i][j] == -1) {
				vacuum_row.push_back(i);
			}
		}
	}

	for (int u = 0; u < t; u++) {
		spread();
		anti_clockwise();
		clockwise();
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result += before_spread[i][j];
		}
	}
	result += 2;
	cout << result << "\n";

	return 0;
}