#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L, K;
vector<pair<int, int>> star;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> L >> K;
	star.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> star[i].first >> star[i].second;
	}

	int result = 0;

	for (int i = 0; i < K; i++) {
		pair<int, int> first_star = star[i];
		for (int j = 0; j < K; j++) {
			pair<int, int> second_star = star[j];
			int temp_result = 0;
			int start_row = min(first_star.first, second_star.first);
			int start_col = min(first_star.second, second_star.second);
			for (int u = 0; u < K; u++) {
				if (start_row <= star[u].first && start_row + L >= star[u].first && start_col <= star[u].second && start_col + L >= star[u].second) {
					temp_result++;
				}
			}
			result = max(result, temp_result);
		}
	}

	cout << K - result << "\n";

	return 0;
}