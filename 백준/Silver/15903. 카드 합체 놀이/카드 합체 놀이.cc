#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		sort(v.begin(), v.end());
		long long temp = v[0] + v[1];
		v[0] = temp;
		v[1] = temp;
	}
	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += v[i];
	}
	cout << result << '\n';
	return 0;
}