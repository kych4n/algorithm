#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int k, n;
long long max_value = 0, result = 0;
vector<long long> lines(10000);

void solve(long long start, long long end) {
    long long mid, temp_count;
    while (start <= end) {
        mid = (start + end) / 2;
        temp_count = 0;
        for (int i = 0; i < k; i++) {
            temp_count += lines[i] / mid;
        }
        if (temp_count < n) {
            end = mid - 1;
        } else {
            start = mid + 1;
            result = max(result, mid);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> lines[i];
        max_value = max(max_value, lines[i]);
    }
    solve(1, max_value);
    cout << result << "\n";
    return 0;
}
