#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int n, x;
    string command;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else if (command == "size") {
            cout << s.size() << "\n";
        } else if (command == "empty") {
            if (s.size() == 0) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (command == "top") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }
    return 0;
}
