#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, min_price = 1e9 + 7;
long long result;
vector<int> demands;
vector<int> prices;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> x;
		demands.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		prices.push_back(x);
	}
	for (int i = 0; i < n - 1; i++) {
		min_price = min(min_price, prices[i]);
		result += min_price * demands[i];
	}
	cout << result << "\n";
	return 0;
}