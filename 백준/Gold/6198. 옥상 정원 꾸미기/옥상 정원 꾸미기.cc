#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, h;
long long result = 0;
stack<int> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop();
		}
		if (s.empty()) {
			s.push(h);
		}
		else if (s.top() > h) {
			result += s.size();
			s.push(h);
		}
	}
	

	cout << result << "\n";
	return 0;
}
