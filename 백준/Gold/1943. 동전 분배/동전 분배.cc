#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    N가지 종류의 동전을 각각 몇 개씩 주셨을 때, 그 돈을 반으로 나눌 수 있는지 없는지 판단

    - 절반으로 나누기? 500 = 100 * 5이 가능한 경우도 있으므로 X
    - 조합 만들기 -> 백트래킹X, 투포인터X, DP
    - DP 최대 50000, 각 분배의 합을 의미
    - 
*/

struct Coin {
    int v, c;
};

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int t = 0; t < 3; t++) {
        cin >> N;
        int total_val = 0;
        vector<Coin> coins(N);
        for (int i = 0; i < N; i++) {
            cin >> coins[i].v >> coins[i].c;
            total_val += coins[i].v * coins[i].c;
        }

        if (total_val % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        int max_val = total_val / 2;
        vector<bool> dp(max_val + 1);
        dp[0] = true;

        for (const Coin& coin : coins) {
            for (int cur_val = max_val; cur_val >= coin.v; cur_val--) {
                if (dp[cur_val - coin.v]) {
                    for (int k = 0; k < coin.c && cur_val + k * coin.v <= max_val; k++) {
                        dp[cur_val + k * coin.v] = true;
                    }
                }
            }
        }

        cout << (dp[max_val] ? 1 : 0) << "\n";

    }
    
    return 0;
}