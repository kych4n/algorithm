#include <iostream>
using namespace std;

int solve(int n) {
    int current_number = 666;
    string current_string;
    string APOCALYPSE_NUMBER = "666";
    while (n > 0) {
        current_string = to_string(current_number);
        if (current_string.find(APOCALYPSE_NUMBER) != -1) {
            n -= 1;
        }
        current_number += 1;
    }
    return current_number - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}