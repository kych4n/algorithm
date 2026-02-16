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
    
    for (int i = 0; i < N; i++) {
        int target = A[i];
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
            int sum = A[left] + A[right];
            if (target > sum) {
                left++;
            }
            else if (target == sum) {
                visited[i] = true;
                break;
            }
            else {
                right--;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) result++;
    }
    cout << result << "\n";
    return 0;
}