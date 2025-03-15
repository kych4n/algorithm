#include <iostream>
#include <stack>
using namespace std;

bool solve(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
        } else if (str[i] == ')' || str[i] == ']') {
            if (!s.empty()) {
                if ((s.top() == '(' && str[i] == ')') || (s.top() == '[' && str[i] == ']')) {
                    s.pop();
                } else
                    return false;
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
    string str;
    while (true) {
        getline(cin, str);
        if (str == ".")
            break;
        if (solve(str)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
    return 0;
}
