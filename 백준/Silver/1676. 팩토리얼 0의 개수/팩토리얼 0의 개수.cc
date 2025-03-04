#include <iostream>
using namespace std;

int get_five_count(int n) {
    int five_count = 0;
    while (n != 0 && n % 5 == 0) {
        five_count += 1;
        n /= 5;
    }
    return five_count;
}

int solve(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += get_five_count(i);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
