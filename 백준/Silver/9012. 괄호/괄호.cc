#include <iostream>
#include <stack>
using namespace std;

int n;
string str;

bool solve(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return false;
            }
        }
    }
    if (s.empty())
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (solve(str)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
