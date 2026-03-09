#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    1 2 3 4 5 6 7 -> 3 7 5 2 6 1 4
    번호 순서대로 배치하기 위해 옮겨지는 아이의 최소 수를 구하시오

    - N = 200
    - 무엇을 옮겨야 할까? -> 이미 잘 자리잡고 있는 것은 옮기지 않음 -> 그럼 이미 잘 자리잡고 있는 것이 뭔데? -> 오름차순을 많이 유지하고 있는 것
    - 오름차순을 유지하는 최장 수열을 구하고, 전체 수에서 빼기
    - 오름차순인 최장 수열을 어떻게 구할까?
        1. 스택을 이용 - X
        2. 이어붙이기
*/

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> height(N);
    for (int i = 0; i < N; i++) cin >> height[i];

    vector<int> dp(N, 1);
    int max_value = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (height[i] > height[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                max_value = max(max_value, dp[i]);
            }
        }
    }
    
    cout << N - max_value << "\n";
    return 0;
}