#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    [입력] 추들의 무게와 확인할 구슬들의 무게
    [출력] 주어진 추만을 사용하여 구슬의 무게를 확인할 수 있는가

    - 구슬의 무게는 모르고 추의 무게만 아는 상태
    - 어떤 추를 왼쪽, 오른쪽, 안씀
*/

int N, M, chu, bead;
const int delta = 15000;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<bool>> dp(N + 1, vector<bool>(delta * 2 + 1));
    dp[0][delta] = true;
    for (int i = 1; i <= N; i++) {
        cin >> chu;
        for (int j = -delta; j <= delta; j++) {
            if (dp[i - 1][j + delta]) {
                if (j - chu + delta >= 0) {
                    dp[i][j - chu + delta] = true;
                }
                if (j + chu + delta <= 2 * delta) {
                    dp[i][j + chu + delta] = true;
                }
                dp[i][j + delta] = true;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> bead;
        cout << (dp[N][bead + delta] ? 'Y' : 'N') << " ";
    }

    return 0;
}