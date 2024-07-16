#include <iostream>
#include <queue>
using namespace std;

int dh[] = { -1,1,0,0,0,0 };
int dl[] = { 0,0,0,0, -1,1 };
int dw[] = { 0,0,-1,1,0,0 };

int m, n, h, day = 0;
int box[100][100][100] = {0, };
bool not_yet = false;
queue<vector<int>> q;

void bfs() {
	while (!q.empty()) {
		bool is_changed = false;
		int cur_size = q.size();
		for (int j = 0; j < cur_size; j++) {
			int cur_h = q.front()[0];
			int cur_l = q.front()[1];
			int cur_w = q.front()[2];
			q.pop();
			for (int i = 0; i < 6; i++) {
				int new_h = cur_h + dh[i];
				int new_l = cur_l + dl[i];
				int new_w = cur_w + dw[i];
				if (!(new_h >= 0 && new_h < h && new_l >= 0 && new_l < n && new_w >= 0 && new_w < m)) {
					continue;
				}
				if (box[new_h][new_l][new_w] == 0) {
					q.push({ new_h, new_l, new_w });
					box[new_h][new_l][new_w] = 1;
					is_changed = true;
				}
			}
		}
		if (is_changed){
			day += 1;
		}
	}
}

int main(void)
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					q.push({ i,j,k });
				}
				if (box[i][j][k] == 0){
					not_yet = true;
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << day << "\n";
	return 0;
}