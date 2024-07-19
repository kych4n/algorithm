#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int height, result = 0;
		vector<int> h(20);
		cin >> n;
		for (int j = 0; j < 20; j++) {
			cin >> h[j];
		}
		for (int j = 0; j < 20; j++) {
			for (int k = j + 1; k < 20; k++) {
				if (h[j] > h[k]) {
					result += 1;
				}
			}
		}
		cout << n << " " << result << "\n";
	}
	return 0;
}