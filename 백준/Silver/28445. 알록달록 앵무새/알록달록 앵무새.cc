#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> s;
string color;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		cin >> color;
		s.insert(color);
	}

	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end());

	int size = v.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << v[i] << " " << v[j] << "\n";
		}
	}

	return 0;
}
