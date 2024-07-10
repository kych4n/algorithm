#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
string temp;
vector<vector<int>> miro(100, vector<int>(100));
vector<vector<int>> dp(100, vector<int>(100, 1e9+7));
queue<pair<int, int>> q;

void bfs(){
	dp[0][0] = 1;
	q.push({0, 0});
	while (!q.empty()){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i=0; i<4; i++){
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (!(new_x >= 0 && new_x < n && new_y >=0 && new_y < m) || !miro[new_x][new_y]) {
				continue;
			}
			if (dp[new_x][new_y] > dp[cur_x][cur_y] + 1){
				q.push({new_x, new_y});
				dp[new_x][new_y] = dp[cur_x][cur_y] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> temp;
		for (int j=0; j<m; j++){
			miro[i][j] = temp[j] - '0';
		}
	}
	bfs();
	cout << dp[n-1][m-1] << "\n";
	return 0;
}