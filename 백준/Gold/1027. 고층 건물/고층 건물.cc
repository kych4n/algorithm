#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, result = 0;
vector<double> height;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	height.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	for (int i = 0; i < N; i++) {
		int temp_result = 0;
		double min_slope = 1e9 + 7;
		for (int j = i - 1; j >= 0; j--) {
			double slope = (height[i] - height[j]) / (i - j);
			if (min_slope > slope) {
				temp_result += 1;
				min_slope = slope;
			}
			else if (slope == 0 && abs(i - j) == 1) {
				temp_result += 1;
				min_slope = slope;
			}
		}
		double max_slope = -(1e9 + 7);
		for (int j = i + 1; j < N; j++) {
			double slope = (height[i] - height[j]) / (i - j);
			if (max_slope < slope) {
				temp_result += 1;
				max_slope = slope;
			}
		}
		result = max(result, temp_result);
	}
	cout << result << "\n";
	return 0;
}