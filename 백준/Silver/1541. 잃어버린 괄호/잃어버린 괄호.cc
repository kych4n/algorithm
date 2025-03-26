#include <iostream>
using namespace std;

string expression;

int solve(string expression) {
    int result = 0;
    string number = "";
    bool minusSignAppeared = false;
    for (char character: expression) {
        if (!(character == '+' || character == '-')) {
            number += character;
        } else {
            if (minusSignAppeared) {
                result -= stoi(number);
            } else {
                result += stoi(number);
            }
            number = "";
            if (character == '-') {
                minusSignAppeared = true;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> expression;
    cout << solve(expression + "+") << "\n";
    return 0;
}
