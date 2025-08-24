#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, result = 0;
string location;
vector<bool> eated(20000);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> location;
	for (int i = 0; i < n; i++) {
		if (location[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j >= 0 && j < n && location[j] == 'H' && !eated[j]) {
					eated[j] = true;
					result += 1;
					break;
				}
			}
		}
	}
	cout << result << "\n";
	return 0;
}