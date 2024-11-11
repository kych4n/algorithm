#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int MAX = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int start = 0, end = 0, result = MAX, sum = 0;
	while (start <= end) {
		if (sum >= s) {
			result = min(result, end - start);
			sum -= v[start++];
		}
		else if (end == n) {
			break;
		}
		else {
			sum += v[end++];
		}
	}
	if (result == MAX) {
		cout << 0 << "\n";
	}
	else {
		cout << result << "\n";
	}
	return 0;
}