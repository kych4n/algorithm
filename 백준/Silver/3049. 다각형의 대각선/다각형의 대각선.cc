#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << n * (n - 1) * (n - 2) * (n - 3) / 24 << "\n";

	return 0;
}