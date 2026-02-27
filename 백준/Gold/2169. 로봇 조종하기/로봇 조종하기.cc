#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MIN = -(1e9 + 7);
int N, M;
int mars[1000][1000];
int dp[1000][1000][3];  // 0: 왼, 1: 오, 2: 아
int dr[] = { 1,0,0 };
int dc[] = { 0,-1,1 };

bool is_in(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mars[i][j];
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = MIN;
            }
        }
    }

    dp[0][0][0] = mars[0][0];
    dp[0][0][1] = mars[0][0];
    dp[0][0][2] = mars[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) continue;
            // 위에서 옴
            if (is_in(i - 1, j)) {
                int before_max_value = MIN;
                for (int k = 0; k < 3; k++) {
                    before_max_value = max(before_max_value, dp[i - 1][j][k]);
                }
                dp[i][j][2] = max(dp[i][j][2], before_max_value + mars[i][j]);
            }
            // 왼쪽에서 옴
            if (is_in(i, j - 1)) {
                int before_max_value = MIN;
                for (int k = 0; k < 3; k++) {
                    if (k == 1) continue;
                    before_max_value = max(before_max_value, dp[i][j - 1][k]);
                }
                dp[i][j][0] = max(dp[i][j][0], before_max_value + mars[i][j]);
            }
        }
        if (i == 0) continue;
        for (int j = M - 1; j >= 0; j--) {
            if (i == 0 && j == 0) continue;
            // 오른쪽에서 옴
            if (is_in(i, j + 1)) {
                int before_max_value = MIN;
                for (int k = 0; k < 3; k++) {
                    if (k == 0) continue;
                    before_max_value = max(before_max_value, dp[i][j + 1][k]);
                }
                dp[i][j][1] = max(dp[i][j][1], before_max_value + mars[i][j]);
            }
        }
    }

    int max_val = MIN;
    for (int i = 0; i < 3; i++) {
        max_val = max(max_val, dp[N - 1][M - 1][i]);
    }
    cout << max_val << "\n";
    return 0;
}