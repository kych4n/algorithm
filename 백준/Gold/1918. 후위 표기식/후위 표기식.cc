#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string eq;
stack<char> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> eq;
	for (int i = 0; i < eq.length(); i++) {
		if (eq[i] >= 'A' && eq[i] <= 'Z') {
			cout << eq[i];
		}
		else if (eq[i] == '(') {
			s.push(eq[i]);
		}
		else if (eq[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (eq[i] == '*' || eq[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(eq[i]);
		}
		else if (eq[i] == '+' || eq[i] == '-') {
			while (!s.empty() && (s.top() != '(')) {
				cout << s.top();
				s.pop();
			}
			s.push(eq[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	
	return 0;
}