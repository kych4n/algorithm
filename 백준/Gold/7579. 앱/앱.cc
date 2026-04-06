#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

/*
    M이 추가로 필요할 때, c가 최소가 되도록 m에서 뽑기
    - m에서 선택했을 때, M바이트 이상을 만족해야 함
    - c의 합이 최소가 되어야 함

    - 넣냐마냐 냅색
*/

int N, M;
const int INF = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<int> m(N + 1);
    vector<int> c(N + 1);

    int total_sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        total_sum += c[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(total_sum + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= total_sum; j++) {
            if (j - c[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int cur_c = 0; cur_c <= total_sum; cur_c++) {
        if (dp[N][cur_c] >= M) {
            cout << cur_c << "\n";
            break;
        }
    }
    return 0;
}