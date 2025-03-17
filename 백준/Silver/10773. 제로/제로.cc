#include <iostream>
#include <stack>
using namespace std;

int n, number, result = 0;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number != 0) {
            s.push(number);
        } else {
            s.pop();
        }
    }
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    cout << result << "\n";
    return 0;
}
