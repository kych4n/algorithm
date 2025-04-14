#include <iostream>
#include <vector>
using namespace std;

constexpr int DIVISION = 10007;

int solve(int n) {
    vector<int> dp(1001);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i] + 2 * dp[i - 2]) % DIVISION;
        dp[i] = (dp[i] + dp[i - 1]) % DIVISION;
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
