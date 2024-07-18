#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<vector<char>> room(n + 1, vector<char>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> str;
		room[i][n] = 'X';
		room[n][i] = 'X';
		for (int j = 0; j < n; j++) {
			room[i][j] = str[j];
		}
	}
	int w = 0; int h = 0;
	for (int i = 0; i <= n; i++) {
		int count = 0;
		for (int j = 0; j <= n; j++) {
			if (room[i][j] == '.') {
				count += 1;
			}
			else if (room[i][j] == 'X') {
				if (count >= 2) {
					w += 1;
				}
				count = 0;
			}
		}
	}
	for (int j = 0; j <= n; j++) {
		int count = 0;
		for (int i = 0; i <= n; i++) {
			if (room[i][j] == '.') {
				count += 1;
			}
			else if (room[i][j] == 'X') {
				if (count >= 2) {
					h += 1;
				}
				count = 0;
			}
		}
	}
	cout << w << " " << h << "\n";
	return 0;
}