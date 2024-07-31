#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, t, p;
vector<int> shirts(6);

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> shirts[i];
	}
	cin >> t >> p;
	
	int shirts_bundle = 0;
	for (int i = 0; i < 6; i++) {
		shirts_bundle += shirts[i] / t;
		if (shirts[i] % t != 0) {
			shirts_bundle += 1;
		}
	}

	cout << shirts_bundle << "\n" << n / p << " " << n % p << "\n";

	return 0;
}