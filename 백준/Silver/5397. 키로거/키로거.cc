#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        string cmd;
        cin >> cmd;
        int L = cmd.length();
        stack<char> ls, rs;
        for (const char& c : cmd) {
            if (c == '<') {
                if (!ls.empty()) {
                    rs.push(ls.top());
                    ls.pop();
                }
            }
            else if (c == '>') {
                if (!rs.empty()) {
                    ls.push(rs.top());
                    rs.pop();
                }
            }
            else if (c == '-') {
                if (!ls.empty()) {
                    ls.pop();
                }
            }
            else {
                ls.push(c);
            }
        }

        while (!ls.empty()) {
            rs.push(ls.top());
            ls.pop();
        }

        while (!rs.empty()) {
            cout << rs.top();
            rs.pop();
        }
        cout << "\n";
    }

    return 0;
}