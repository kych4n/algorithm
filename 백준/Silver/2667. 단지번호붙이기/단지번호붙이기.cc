#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n, count = 0;
string row;
vector<vector<int>> mapp(25, vector<int>(25));
priority_queue<int, vector<int>, greater<int>> pq;

int bfs(int start_x, int start_y){
	int area = 1;
	queue<pair<int, int>> q;
	q.push({start_x, start_y});
	mapp[start_x][start_y] = 0;
	while (!q.empty()){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i=0; i<4; i++){
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (!(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n)){
				continue;
			}
			if (mapp[new_x][new_y]){
				area += 1;
				mapp[new_x][new_y] = 0;
				q.push({new_x, new_y});
			}
		} 
	}
	return area;
}

int main(void) {
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> row;
		for (int j=0; j<n; j++){
			mapp[i][j] = row[j] - '0';
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (mapp[i][j]){
				count += 1;
				pq.push(bfs(i, j));
			}
		}
	}
	cout << count << "\n";
	while (!pq.empty()){
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}