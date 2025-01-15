#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	cout << ((h - 1) / (n + 1) + 1) * ((w - 1) / (m + 1) + 1) << "\n";
	return 0;
}