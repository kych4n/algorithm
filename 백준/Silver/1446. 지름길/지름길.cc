#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, d, start, endd, cost, possible_start_point, current_cost;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
vector<int> min_cost(10001);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> start >> endd >> cost;
		pq.push({ start, endd, cost });
	}
	for (int i = 0; i <= d; i++) {
		min_cost[i] = i;
	}
	while (!pq.empty()) {
		start = pq.top()[0];
		endd = pq.top()[1];
		cost = pq.top()[2];
		pq.pop();
		if (min_cost[endd] > min_cost[start] + cost) {
			min_cost[endd] = min_cost[start] + cost;
			for (int next_end = endd + 1; next_end <= d; next_end++) {
				min_cost[next_end] = min(min_cost[next_end], min_cost[endd] + next_end - endd);
			}
		}
	}
	cout << min_cost[d] << "\n";
	return 0;
}