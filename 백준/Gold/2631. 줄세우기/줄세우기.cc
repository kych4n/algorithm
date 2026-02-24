#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int next;
		cin >> next;
		if (v.empty() || v.back() < next) {
			v.push_back(next);
		}
		else {
			v[upper_bound(v.begin(), v.end(), next) - v.begin()] = next;
		}
	}
	
	cout << n - v.size() << '\n';

	return 0;
}