#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k, n;
	char command;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		priority_queue<int> max_pq;
		priority_queue<int, vector<int>, greater<int>> min_pq;
		map<int, int> save;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> command >> n;
			if (command == 'I') {
				max_pq.push(n);
				min_pq.push(n);
				if (!save.count(n)) {
					save[n] = 1;
				}
				else {
					save[n] += 1;
				}
			}
			else if (command == 'D') {
				if (n == 1) {
					while (!max_pq.empty() && save[max_pq.top()] == 0) {
						max_pq.pop();
					}
					if (max_pq.empty()) {
						continue;
					}
					save[max_pq.top()] -= 1;
					max_pq.pop();
				}
				else if (n == -1) {
					while (!min_pq.empty() && save[min_pq.top()] == 0) {
						min_pq.pop();
					}
					if (min_pq.empty()) {
						continue;
					}
					save[min_pq.top()] -= 1;
					min_pq.pop();
				}
			}
		}
		while (!max_pq.empty() && save[max_pq.top()] == 0) {
			max_pq.pop();
		}
		while (!min_pq.empty() && save[min_pq.top()] == 0) {
			min_pq.pop();
		}
		if (max_pq.empty() && min_pq.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << max_pq.top() << " " << min_pq.top() << "\n";
		}
	}
	return 0;
}