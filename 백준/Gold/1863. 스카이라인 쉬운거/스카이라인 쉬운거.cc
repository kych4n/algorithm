#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> v;
int n, x, y, result = 0;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (y == 0) {
			v.clear();
			continue;
		}
		
		if (v.empty()) {
			result += 1;
			v.push_back(y);
			continue;
		}

		bool is_one = false;
		while (!v.empty() && v.back() >= y) {
			if (v.back() == y) {
				is_one = true;
			}
			v.pop_back();
		}
		v.push_back(y);
		if (!is_one) {
			result += 1;
		}
	}

	cout << result << "\n";

	return 0;
}