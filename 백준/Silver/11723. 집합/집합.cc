#include <iostream>
#include <vector>
using namespace std;

vector<int> s(21);

void solve(string command, int x) {
    if (command == "add") {
        s[x] = 1;
    } else if (command == "remove") {
        s[x] = 0;
    } else if (command == "check") {
        cout << s[x] << "\n";
    } else if (command == "toggle") {
        s[x] = abs(1 - s[x]);
    } else if (command == "all") {
        s = vector<int>(21, 1);
    } else if (command == "empty") {
        s = vector<int>(21, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string command;
    int n, x = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command != "all" && command != "empty") {
            cin >> x;
        }
        solve(command, x);
    }
    return 0;
}
