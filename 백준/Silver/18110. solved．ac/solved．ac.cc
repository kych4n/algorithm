#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double n;
	cin >> n;
	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	double m = round(n * 0.15);
	double result = 0;
	for (int i = m; i < n-m; i++) {
		result += v[i];
	}
	cout << round(result/(n-(m*2))) << "\n";
	return 0;
}