#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int t, h;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		int sum = 0, max_h = 0;
		for (int j = 0; j < 6; j++) {
			cin >> h;
			max_h = max(max_h, h);
			sum += h;
		}
		int temp = sum + max_h + 1;
		if (temp % 7 == 0) {
			cout << max_h + 1 << "\n";
		}
		else {
			cout << (temp / 7 + 1) * 7 - sum << "\n";
		}
	}
	
	return 0;
}
