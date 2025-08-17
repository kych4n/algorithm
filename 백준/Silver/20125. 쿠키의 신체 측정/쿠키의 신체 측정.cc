#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> board(1000);
pair<int, int> heart;
int leftArm, rightArm, waist, leftLeg, rightLeg;

void findHeart() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '*') {
				heart = { i + 1, j };
				return;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	findHeart();
	for (int i = 0; i < heart.second; i++) {
		if (board[heart.first][i] == '*') {
			leftArm += 1;
		}
	}
	for (int i = heart.second + 1; i < n; i++) {
		if (board[heart.first][i] == '*') {
			rightArm += 1;
		}
	}
	for (int i = heart.first + 1; i < n; i++) {
		if (board[i][heart.second] == '*') {
			waist += 1;
		}
	}
	for (int i = heart.first + 2; i < n; i++) {
		if (board[i][heart.second - 1] == '*') {
			leftLeg += 1;
		}
	}for (int i = heart.first + 2; i < n; i++) {
		if (board[i][heart.second + 1] == '*') {
			rightLeg += 1;
		}
	}
	cout << heart.first + 1 << " " << heart.second + 1<< "\n";
	cout << leftArm << " " << rightArm << " " << waist << " " << leftLeg << " " << rightLeg << "\n";
	return 0;
}