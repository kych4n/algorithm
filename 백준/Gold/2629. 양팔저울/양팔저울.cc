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

bool dp[31][15001];
int N, M, weights[31];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        cin >> weights[i];
        for (int j = 0; j <= 15000; j++) {
            if (dp[i - 1][j]) {
                if (j + weights[i] <= 15000) {
                    dp[i][j + weights[i]] = true;
                }
                dp[i][abs(j - weights[i])] = true;
                dp[i][j] = true;
            }
        }
    }

    cin >> M;
    int target;
    for (int i = 0; i < M; i++) {
        cin >> target;
        if (target > 15000) cout << 'N' << " ";
        else cout << (dp[N][target] ? 'Y' : 'N') << " ";
    }

    return 0;
}