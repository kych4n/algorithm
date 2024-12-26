#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, rank;
	cin >> t;
	for (int i = 0; i < t; i++) {
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> rank;
			pq.push(rank);
			q.push(make_pair(rank, j));
		}
		int count = 1;
		while (true) {
			if (q.front().first == pq.top()) {
				if (q.front().second == m) {
					cout << count << "\n";
					break;
				}
				else {
					pq.pop();
					q.pop();
					count++;
				}
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
	
	return 0;
}