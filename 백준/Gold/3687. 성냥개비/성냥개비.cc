#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.
*/

typedef long long ll;
ll need[8] = { 0,0,1,7,4,2,0,8 };
vector<ll> dp(101, INT64_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;
    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            if (i - j < 2) continue;
            dp[i] = min(dp[i], dp[i - j] * 10 + need[j]);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        /*
            가장 작은 수 
        */
        cout << dp[N] << " ";

        /*
            가장 큰 수 = 자릿수가 많아야 함 = 성냥개비를 적게 쓰는 것을 최대한 많이 사용
            필요한 수가 적은 것이 1(2개 필요)과 7(3개 필요) -> 홀수, 짝수에 따라 구분해서 1과 7을 사용한다면 자릿수를 많이 늘릴 수 있음
        */
        if (N % 2 == 1) {
            cout << 7;
            for (int i = 0; i < (N - 3) / 2; i++) {
                cout << 1;
            }
        }
        else {
            for (int i = 0; i < N / 2; i++) {
                cout << 1;
            }
        }

        cout << "\n";
    }

    return 0;
}