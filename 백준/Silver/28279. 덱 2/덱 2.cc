#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	deque<int> dq;
	int n, a, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> x;
			dq.push_front(x);
		}
		else if (a == 2) {
			cin >> x;
			dq.push_back(x);
		}
		else if (a == 3) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (a == 4) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (a == 5) {
			cout << dq.size() << "\n";
		}
		else if (a == 6) {
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (a == 7) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (a == 8) {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
	
	return 0;
}