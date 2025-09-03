#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, a, result = 0;
queue<int> q;
vector<int> current_count(100001);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (current_count[a] >= k) {
			while (q.front() != a) {
				current_count[q.front()] -= 1;
				q.pop();
			}
			current_count[q.front()] -= 1;
			q.pop();
		}
		if (current_count[a] < k) {
			q.push(a);
			current_count[a] += 1;
			result = max(result, (int)q.size());
		}
	}
	cout << result << "\n";
	return 0;
}