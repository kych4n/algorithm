#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m, d, result = 0;
vector<vector<int>> board(15, vector<int>(15));
vector<vector<int>> temp_board(15, vector<int>(15));
vector<int> temp(3);

void dead() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 2) {
				board[i][j] = 0;
			}
		}
	}
}

bool shoot(int archor_x, int archor_y) {
	for (int j = 1; j <= d; j++) {
		for (int k = -(j - 1); k <= j - 1; k++) {
			int enemy_x = archor_x - (j - abs(k));
			int enemy_y = archor_y + k;
			if (enemy_x >= 0 && enemy_x < n && enemy_y >= 0 && enemy_y < m) {
				if (board[enemy_x][enemy_y] == 1) {
					board[enemy_x][enemy_y] = 2;
					return true;
				}
				else if (board[enemy_x][enemy_y] == 2) {
					return false;
				}
			}
		}
	}
	return false;
}

void game(vector<int> archors) {
	int temp_result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (shoot(n - i, archors[j])) {
				temp_result += 1;
			}
		}
		dead();
	}
	result = max(result, temp_result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	temp_board = board;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				board = temp_board;
				temp = { i, j, k };
				game(temp);
			}
		}
	}
	cout << result << "\n";
	
	return 0;
}