#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, white = 0, blue = 0;
int paper[128][128];

void make_result(int cur_x, int cur_y, int length) {
	int color = paper[cur_x][cur_y];
	for (int i = cur_x; i < cur_x+length; i++) {
		for (int j = cur_y; j < cur_y+length; j++) {
			if (color != paper[i][j]) {
				make_result(cur_x, cur_y, length / 2);
				make_result(cur_x, cur_y + length / 2, length / 2);
				make_result(cur_x + length / 2, cur_y, length / 2);
				make_result(cur_x + length / 2, cur_y + length / 2, length / 2);
				return;
			}
		}
	}
	if (color == 1) {
		blue += 1;
	}
	else if (color == 0) {
		white += 1;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	make_result(0, 0, n);
	cout << white << "\n" << blue << "\n";
	return 0;
}