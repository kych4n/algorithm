#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> A(N);
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = A[i] + A[j];
            int target_lower_idx = lower_bound(A.begin(), A.end(), sum) - A.begin();
            int target_upper_idx = upper_bound(A.begin(), A.end(), sum) - A.begin();
            if (target_lower_idx >= N) break;
            if (target_lower_idx == i || target_lower_idx == j) continue;
            if (A[target_lower_idx] == sum) {
                if (visited[target_lower_idx]) continue;
                for (int k = target_lower_idx; k < target_upper_idx; k++) {
                    visited[k] = true;
                }
            };
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) result++;
    }
    cout << result << "\n";
    return 0;
}