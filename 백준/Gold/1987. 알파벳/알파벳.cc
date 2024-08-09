#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, result = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<char>> board(20, vector<char>(20));
vector<bool> visited(26);
string s;

void dfs(int cur_x, int cur_y, int temp_result) {
	result = max(result, temp_result);

	for (int i = 0; i < 4; i++) {
		int new_x = cur_x + dx[i];
		int new_y = cur_y + dy[i];
		if (!(new_x >= 0 && new_x < r && new_y >= 0 && new_y < c)) {
			continue;
		}
		int new_alphabet = board[new_x][new_y];
		if (!visited[new_alphabet - 'A']) {
			visited[new_alphabet - 'A'] = true;
			dfs(new_x, new_y, temp_result + 1);
			visited[new_alphabet - 'A'] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j] = s[j];
		}
	}

	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << result << "\n";

	return 0;
}