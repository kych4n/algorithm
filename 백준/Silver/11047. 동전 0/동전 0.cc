#include <iostream>
#include <queue>
using namespace std;

vector<int> coins;

void getCoins(int n) {
    int coin;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        coins.push_back(coin);
    }
}

int solve(int n, int k) {
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        count += k / coins[i];
        k %= coins[i];
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    getCoins(n);
    cout << solve(n, k) << "\n";
    return 0;
}
