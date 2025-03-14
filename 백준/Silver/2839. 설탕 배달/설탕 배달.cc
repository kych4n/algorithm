#include <iostream>
using namespace std;

int solve(int n) {
    int count_five = n / 5;
    int count_three = n % 5 / 3;
    while (count_five >= 0) {
        if (count_five * 5 + count_three * 3 != n) {
            count_five -= 1;
            count_three += 2;
        } else {
            return count_five + count_three;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
