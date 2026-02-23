#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<long long> lecture(N);
    long long left = 0, right = 0;
    for (int i = 0; i < N; i++) {
        cin >> lecture[i];
        left = max(left, lecture[i]);
        right += lecture[i];
    }

    long long result = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int bluray_count = 1;
        long long temp_sum = 0;

        for (int i = 0; i < N; i++) {
            if (temp_sum + lecture[i] > mid) {
                bluray_count++;
                temp_sum = lecture[i];
            }
            else {
                temp_sum += lecture[i];
            }
        }

        if (bluray_count <= M) {
            result = min(result, mid);
            right = mid - 1;
        }
        else if (bluray_count > M) {
            left = mid + 1;
        }
    }

    cout << result << "\n";

    return 0;
}