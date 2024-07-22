#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<char>> painting1(100, vector<char>(100));
vector<vector<char>> painting2(100, vector<char>(100));
int a = 0, b = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs1(int start_x, int start_y) {
	char color = painting1[start_x][start_y];
	painting1[start_x][start_y] = 'X';
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n)) {
				continue;
			}
			if (painting1[new_x][new_y] == color) {
				painting1[new_x][new_y] = 'X';
				q.push({ new_x, new_y });
			}
		}
	}
}

void bfs2(int start_x, int start_y) {
	char color = painting2[start_x][start_y];
	painting2[start_x][start_y] = 'X';
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n)) {
				continue;
			}
			if (((color == 'R' || color == 'G') && (painting2[new_x][new_y] == 'R' || painting2[new_x][new_y] == 'G')) || (color == 'B' && painting2[new_x][new_y] == 'B')) {
				painting2[new_x][new_y] = 'X';
				q.push({ new_x, new_y });
			}
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> painting1[i][j]; 
			painting2[i][j] = painting1[i][j]; 
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (painting1[i][j] != 'X') {
				a += 1;
				bfs1(i, j);
			}
			if (painting2[i][j] != 'X') {
				b += 1;
				bfs2(i, j);
			}
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}