#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

int N, result = 0;
string a, b;

char change(char c) {
    if (c == '0') {
        return '1';
    }
    else {
        return '0';
    }
}

int simulation(string current, bool first_pressed) {
    int result = 0;

    if (first_pressed) {
        current[0] = change(current[0]);
        current[1] = change(current[1]);
        result += 1;
    }

    int length = current.length();
    for (int i = 1; i < length; i++) {
        if (b[i - 1] == current[i - 1]) continue;
        result += 1;
        if (i == length - 1) {
            current[i] = change(current[i]);
            current[i - 1] = change(current[i - 1]);
        }
        else {
            current[i] = change(current[i]);
            current[i + 1] = change(current[i + 1]);
            current[i - 1] = change(current[i - 1]);
        }
    }
    if (current == b) {
        return result;
    }
    return 1e9 + 7;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> a >> b;
    
    int pressed_result = simulation(a, true);
    int unpressed_result = simulation(a, false);
    int result = min(pressed_result, unpressed_result);
    if (result == 1e9 + 7) result = -1;
    cout << result << "\n";

    return 0;
}