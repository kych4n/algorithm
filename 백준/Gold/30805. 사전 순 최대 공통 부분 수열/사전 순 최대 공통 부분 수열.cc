#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, number, limit_a_idx = 0, limit_b_idx = 0;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq2;
vector<int> result;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		pq1.push({ number, i });
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> number;
		pq2.push({ number, i });
	}

	while (!pq1.empty() && !pq2.empty()) {
		if (!pq1.empty() && pq1.top().second < limit_a_idx) {
			pq1.pop();
			continue;
		}
		if (!pq2.empty() && pq2.top().second < limit_b_idx) {
			pq2.pop();
			continue;
		}

		if (pq1.top().first == pq2.top().first) {
			result.push_back(pq1.top().first);
			limit_a_idx = pq1.top().second;
			limit_b_idx = pq2.top().second;
			pq1.pop();
			pq2.pop();
		}
		else if (pq1.top().first > pq2.top().first) {
			pq1.pop();
		}
		else if (pq1.top().first < pq2.top().first) {
			pq2.pop();
		}
	}

	int size = result.size();

	cout << size << "\n";

	for (int i = 0; i < size; i++) {
		cout << result[i] << " ";
	}

	return 0;
}
