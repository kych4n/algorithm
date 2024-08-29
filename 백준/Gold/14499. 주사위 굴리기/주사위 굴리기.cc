#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
vector<vector<int>> map(20, vector<int>(20));
vector<int> dice(7);
int n, m, x, y, k, command, temp;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int u = 0; u < k; u++) {
		cin >> command;
		temp = dice[6];
		if (command == 1) {
			if (y + 1 >= m) {
				continue;
			}
			y++;
			dice[6] = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[4];
			dice[4] = temp;
		}
		else if (command == 2) {
			if (y - 1 < 0) {
				continue;
			}
			y--;
			dice[6] = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[3];
			dice[3] = temp;
		}
		else if (command == 3) {
			if (x - 1 < 0) {
				continue;
			}
			x--;
			dice[6] = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = temp;
		}
		else if (command == 4) {
			if (x + 1 >= n) {
				continue;
			}
			x++;
			dice[6] = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = temp;
		}
		if (map[x][y] == 0) {
			map[x][y] = dice[6];
		}
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1] << "\n";
	}

	return 0;
}