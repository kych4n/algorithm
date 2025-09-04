#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, number;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> number;
		pq.push(number);
		while (pq.size() > n) {
			pq.pop();
		}
	}
	cout << pq.top() << "\n";
	return 0;
}