#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    어떤 수가 다른 수 두 개의 합으로 나타낼 수 있는 것이 몇 개인지 출력하라.
    수의 위치가 다르면 값이 같아도 다른 수이다.

    - 두 개의 합 -> 투 포인터 의심
    - 정렬해두었음 -> i, j의 합, j+1부터 탐색
        - i, j의 합보다 크다 -> i++
        - i, j의 합과 같다 -> 체크하고 차이가 작은 것을 늘리기

        - i, j의 합보다 모두 작다 -> 그럼 나머지 조합에서도 작으므로 끝내기
*/

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<bool> visited(N);

    for (int i = 0; i < N; i++) {
        int left = 0, right = N - 1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            if (A[left] + A[right] == A[i]) {
                visited[i] = true;
                break;
            }
            else if (A[left] + A[right] > A[i]) {
                right--;
            }
            else {
                left++;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            result++;
        }
    }
    cout << result << "\n";

    return 0;
}