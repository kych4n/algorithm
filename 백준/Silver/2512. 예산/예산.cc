#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, max_budget, request;
vector<int> requests;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> request;
		requests.push_back(request);
	}
	cin >> m;
	sort(requests.begin(), requests.end());
	for (int i = 0; i < n; i++) {
		if (requests[i] * (n - i) <= m) {
			max_budget = requests[i];
		}
		else {
			max_budget = m / (n - i);
			break;
		}
		m -= requests[i];
	}
	cout << max_budget << "\n";
	return 0;
}