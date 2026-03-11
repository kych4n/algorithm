#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    지형을 N×M 배열로 단순화 하여 생각하기로 한다.
    로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만, 위쪽으로는 이동할 수 없다. 
    또한 한 번 탐사한 지역은 탐사하지 않기로 한다.
    로봇을 배열의 왼쪽 위 (1, 1)에서 출발시켜 오른쪽 아래 (N, M)으로 보내려고 한다. 
    이때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의 합이 최대가 되도록 하는 프로그램을 작성하시오.
    배열의 각 수는 절댓값이 100을 넘지 않는 정수이다.

    - 새로운 칸의 가치의 합 = 이전 칸의 가치의 합 + 새로운 칸의 가치
    - 오른쪽으로 가며 갱신하는 것과 왼쪽으로 가며 갱신하는 것을 만들고, 다음 줄에는 둘 중 큰 것으로 갱신
*/

int N, M;
int val[1000][1000];
int to_left[1000], to_right[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> val[i][j];
        }
    }

    for (int j = 0; j < M; j++) {
        to_left[j] = INT32_MIN;
        to_right[j] = INT32_MIN;
    }

    to_right[0] = val[0][0];
    for (int j = 1; j < M; j++) {
        to_right[j] = max(to_right[j], to_right[j - 1] + val[0][j]);
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            to_right[j] = max(to_left[j], to_right[j]) + val[i][j];
            to_left[j] = to_right[j];
        }
        for (int j = 1; j < M; j++) {
            to_right[j] = max(to_right[j], to_right[j - 1] + val[i][j]);
        }
        for (int j = M - 2; j >= 0; j--) {
            to_left[j] = max(to_left[j], to_left[j + 1] + val[i][j]);
        }
    }
    cout << max(to_right[M - 1], to_left[M - 1]) << "\n";

    return 0;
}