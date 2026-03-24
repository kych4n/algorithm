#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

/*
    - N가지 종류의 동전을 각각 몇 개씩 주셨을 때, 
    그 돈을 반으로 나눌 수 있는지 없는지 판단하는 것이다.
    -> 전체 총합의 반을 구성할 수 있는지 판단

    
*/

struct Money {
    int v, c;
};

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 0; tc < 3; tc++) {
        int total = 0;

        cin >> N;
        vector<Money> moneys(N);
        for (int i = 0; i < N; i++) {
            cin >> moneys[i].v >> moneys[i].c;
            total += moneys[i].v * moneys[i].c;
        }

        if (total % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        int max_val = total / 2;
        bitset<50001> dp;
        dp[0] = 1;

        for (const Money& m : moneys) {
            int value = m.v;
            int count = m.c;

            for (int k = 1; count > 0; k <<= 1) {
                int num = min(k, count);
                int move = value * num;

                dp |= (dp << move);
                count -= num;

                if (dp[max_val]) break;
            }

            if (dp[max_val]) break;
        }

        cout << (dp[max_val] ? 1 : 0) << "\n";
    }
    
    return 0;
}