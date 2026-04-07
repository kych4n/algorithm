#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    같은 원소가 K개 이하로 들어 있는 최장 연속 부분 수열의 길이

    - N = 200000
    - 원소 당 몇 개인지 기록
    - right : 기록 증가 + 기록 증가했을 때 개수가 K개 초과면, left 증가 + 기록 감소
*/

int N, K;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    vector<int> a(N);
    vector<int> count(100001);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int left, right; left = right = 0;
    int result = 0;
    while (right < N) {
        count[a[right]]++;
        while (count[a[right]] > K) {
            count[a[left]]--;
            left++;
        }
        result = max(result, right - left + 1);
        right++;
    }

    cout << result << "\n";

    return 0;
}