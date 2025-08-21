#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, max_visit_count = 0, duration_count = 0;
vector<int> visit_counts(250000);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> visit_counts[i];
		if (i > 0) {
			visit_counts[i] += visit_counts[i - 1];
		}
		if (i >= x) {
			if (max_visit_count < visit_counts[i] - visit_counts[i - x]) {
				max_visit_count = visit_counts[i] - visit_counts[i - x];
				duration_count = 1;
			}
			else if (max_visit_count == visit_counts[i] - visit_counts[i - x]) {
				duration_count += 1;
			}
		}
	}
	if (max_visit_count == 0) {
		cout << "SAD" << "\n";
		return 0;
	}
	cout << max_visit_count << "\n" << duration_count << "\n";
	return 0;
}