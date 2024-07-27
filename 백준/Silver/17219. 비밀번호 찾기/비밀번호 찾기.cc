#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	string site, passwd;
	cin >> n >> m;
	map<string, string> mp;
	for (int i = 0; i < n; i++) {
		cin >> site >> passwd;
		mp[site] = passwd;
	}
	for (int i = 0; i < m; i++) {
		cin >> site;
		cout << mp[site] << "\n";
	}
	return 0;
}