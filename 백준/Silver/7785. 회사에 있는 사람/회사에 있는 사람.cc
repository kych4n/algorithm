#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n;
string name, state;
map<string, bool> m;
vector<string> result;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		if (state == "enter") {
			if (m.find(name) != m.end()) {
				m[name] = true;
			}
			else {
				m.insert({ name, true });
			}
		}
		else {
			m[name] = false;
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == true) {
			result.push_back(iter->first);
		}
	}
	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
