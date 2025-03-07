#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, number, target;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        A.push_back(number);
    }
    sort(A.begin(), A.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> target;
        if (auto iter = lower_bound(A.begin(), A.end(), target); iter != A.end() && *iter == target) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
