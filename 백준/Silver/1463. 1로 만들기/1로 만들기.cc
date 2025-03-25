#include <iostream>
#include <vector>
using namespace std;

int n;
constexpr int MAX_N = 1000000;
vector<int> operation_counts(MAX_N + 1, 1e9 + 7);

void solve() {
    operation_counts[1] = 0;
    for (int cur_value = 1; cur_value < n; cur_value++) {
        if (cur_value * 3 <= n) {
            operation_counts[cur_value * 3] = min(operation_counts[cur_value * 3], operation_counts[cur_value] + 1);
        }
        if (cur_value * 2 <= n) {
            operation_counts[cur_value * 2] = min(operation_counts[cur_value * 2], operation_counts[cur_value] + 1);
        }
        if (cur_value + 1 <= n) {
            operation_counts[cur_value + 1] = min(operation_counts[cur_value + 1], operation_counts[cur_value] + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    solve();
    cout << operation_counts[n] << "\n";
    return 0;
}
