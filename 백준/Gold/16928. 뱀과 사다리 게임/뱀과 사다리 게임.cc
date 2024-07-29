#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x, y, u, v;
vector<int> link(101);
vector<int> rolling_count(101, 1e9 + 7);

void game() {
	queue<int> q;
	q.push(1);
	rolling_count[1] = 0;
	while (!q.empty()) {
		int cur_loc = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int next_loc = cur_loc + i;
			if (next_loc > 100) {
				continue;
			}
			if (link[next_loc] != 0) {
				next_loc = link[next_loc];
			}
			if (rolling_count[next_loc] > rolling_count[cur_loc] + 1) {
				rolling_count[next_loc] = rolling_count[cur_loc] + 1;
				q.push(next_loc);
			}
		}
		
	}
}

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		link[x] = y;
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		link[u] = v;
	}
	
	game();

	cout << rolling_count[100] << "\n";
	
	return 0;
}