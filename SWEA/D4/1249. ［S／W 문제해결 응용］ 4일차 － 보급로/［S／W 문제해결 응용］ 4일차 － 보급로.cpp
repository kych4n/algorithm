#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int t, n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
string s;
vector<vector<int>> mapp(100, vector<int>(100));
vector<vector<int>> dp(100, vector<int>(100, 1e9+7));

void bfs(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	dp[0][0] = 0;
	while (!q.empty()){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i=0; i<4; i++){
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (!(new_x >= 0 && new_x < n && new_y >=0 && new_y < n)){
				continue;
			}
			if (dp[new_x][new_y] > dp[cur_x][cur_y] + mapp[new_x][new_y]){
				dp[new_x][new_y] = dp[cur_x][cur_y] + mapp[new_x][new_y];
				q.push({new_x, new_y});
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int i=1; i<=t; i++){
		cin >> n;
		for (int j=0; j<n; j++){
			cin >> s;
			for (int k=0; k<n; k++){
				mapp[j][k] = s[k] - '0';
				dp[j][k] = 1e9+7;
			}
		}
		bfs();
		cout << "#" << i << " " << dp[n-1][n-1] << "\n";
	}
	return 0;
}