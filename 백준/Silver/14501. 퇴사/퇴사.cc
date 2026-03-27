#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int T[16];
int P[16];
int result = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> dp(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + T[i] - 1 <= N) {
            dp[i + T[i] - 1] = max(dp[i + T[i] - 1], dp[i - 1] + P[i]);
            result = max(result, dp[i + T[i] - 1]);
        }
    }
    cout << result << "\n";
    

    return 0;
}