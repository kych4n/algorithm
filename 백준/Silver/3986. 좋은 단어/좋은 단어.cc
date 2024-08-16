#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

stack<char> s;
int n, result = 0;
string str;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		while (!s.empty()) {
			s.pop();
		}
		
		cin >> str;
		
		for (int j = 0; j < str.length(); j++) {
			if (s.empty() || s.top() != str[j]) {
				s.push(str[j]);
			}
			else if (s.top() == str[j]) {
				s.pop();
			}
		}

		if (s.empty()) {
			result += 1;
		}
	}
	cout << result << "\n";

	return 0;
}