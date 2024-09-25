#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n, smaller;
vector<int> v(10);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> smaller;
		for (int j = 0; j < n; j++) {
			if (v[j] == 0) {
				smaller -= 1;
			}
			if (smaller == -1) {
				v[j] = i;
				break;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}


	return 0;
}
