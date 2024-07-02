#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;	
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int t, m, n, k, x, y;

void bfs(int start_y, int start_x, vector<vector<int>>& farm){
	queue<pair<int, int>> q;
	farm[start_y][start_x] = 0;
	q.push({start_y, start_x});
	while (!q.empty()){
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i=0; i<4; i++){
			int new_y = cur_y + dy[i];
			int new_x = cur_x + dx[i];
			if (!(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n)){
				continue;
			}
			if (farm[new_y][new_x] == 1){
				farm[new_y][new_x] = 0;
				q.push({new_y, new_x});
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int q=0; q<t; q++){
		cin >> m >> n >> k;
		vector<vector<int>> farm(n, vector<int>(m));
		int number_of_earthworm = 0;
		for (int w=0; w<k; w++){
			cin >> x >> y;
			farm[y][x] = 1;
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (farm[i][j] == 1){
					number_of_earthworm+=1;
					bfs(i, j, farm);
				}
			}
		}
		cout << number_of_earthworm << "\n";
	}
	return 0;
}