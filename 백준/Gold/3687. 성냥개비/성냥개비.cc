#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll num[8] = { 0,0,1,7,4,2,0,8 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    vector<ll> dp(101, 1e18);
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    
    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            if (dp[i - j] == 1e18) continue;
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        cout << dp[N] << " ";

        if (N % 2 == 0) {
            for (int i = 0; i < N / 2; i++) {
                cout << 1;
            }
        }
        else {
            cout << 7;
            for (int i = 0; i < (N - 3) / 2; i++) {
                cout << 1;
            }
        }
        cout << "\n";
    }

    return 0;
}