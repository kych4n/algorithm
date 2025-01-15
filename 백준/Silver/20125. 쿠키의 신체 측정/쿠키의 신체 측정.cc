#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<vector<char>> board(1000, vector<char>(1000));

pair<int, int> get_head() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '*') {
				return { i, j };
			}
		}
	}
}

pair<int, int> get_left_hand(int x, int y) {
	while (y >= 0) {
		if (board[x][y - 1] == '*') {
			y -= 1;
		}
		else {
			break;
		}
	}
	return { x, y };
}

pair<int, int> get_right_hand(int x, int y) {
	while (y < n) {
		if (board[x][y + 1] == '*') {
			y += 1;
		}
		else {
			break;
		}
	}
	return { x, y };
}

pair<int, int> get_waist_or_foot(int x, int y) {
	while (x < n) {
		if (board[x + 1][y] == '*') {
			x += 1;
		}
		else {
			break;
		}
	}
	return { x, y };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	pair<int, int> head = get_head();
	pair<int, int> heart = { head.first + 1, head.second };
	pair<int, int> left_hand = get_left_hand(heart.first, heart.second);
	pair<int, int> right_hand = get_right_hand(heart.first, heart.second);
	pair<int, int> waist = get_waist_or_foot(heart.first + 1, heart.second);
	pair<int, int> left_foot = get_waist_or_foot(waist.first + 1, waist.second - 1);
	pair<int, int> right_foot = get_waist_or_foot(waist.first + 1, waist.second + 1);

	cout << heart.first + 1 << " " << heart.second + 1 << "\n";
	cout << heart.second - left_hand.second << " " << right_hand.second - heart.second << " " << waist.first - heart.first << " " << left_foot.first - waist.first << " " << right_foot.first - waist.first << "\n";
	

	return 0;
}
