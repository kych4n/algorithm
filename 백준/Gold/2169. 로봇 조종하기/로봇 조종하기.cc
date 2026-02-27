#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, M;
int mars[1001][1001];
int dp[1001][1001];
int L2R[1001], R2L[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mars[i][j];
        }
    }

    // 1. 첫 번째 줄 처리 (오직 오른쪽으로만 이동 가능)
    dp[0][0] = mars[0][0];
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + mars[0][j];
    }

    // 2. 두 번째 줄부터 DP 전개
    for (int i = 1; i < N; i++) {
        
        // 왼쪽에서 오른쪽으로 가는 경우 (위에서 내려옴 vs 왼쪽에서 옴)
        L2R[0] = dp[i - 1][0] + mars[i][0];
        for (int j = 1; j < M; j++) {
            L2R[j] = max(dp[i - 1][j], L2R[j - 1]) + mars[i][j];
        }

        // 오른쪽에서 왼쪽으로 가는 경우 (위에서 내려옴 vs 오른쪽에서 옴)
        R2L[M - 1] = dp[i - 1][M - 1] + mars[i][M - 1];
        for (int j = M - 2; j >= 0; j--) {
            R2L[j] = max(dp[i - 1][j], R2L[j + 1]) + mars[i][j];
        }

        // 해당 칸의 최댓값 결정
        for (int j = 0; j < M; j++) {
            dp[i][j] = max(L2R[j], R2L[j]);
        }
    }

    cout << dp[N - 1][M - 1] << "\n";

    return 0;
}