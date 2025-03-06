#include <iostream>
#include <vector>
using namespace std;

int n, number;
vector<int> sequence;

void solve() {
    int current_target_idx = 0;
    vector<char> result;
    vector<int> stack;
    for (int push_number = 1; push_number <= n; push_number++) {
        if (stack.empty() || push_number <= sequence[current_target_idx]) {
            stack.push_back(push_number);
            result.push_back('+');
        }
        if (push_number > sequence[current_target_idx]) {
            cout << "NO" << "\n";
            return;
        }
        while (!stack.empty() && stack.back() == sequence[current_target_idx]) {
            stack.pop_back();
            result.push_back('-');
            current_target_idx += 1;
        }
    }
    if (result.size() != 2 * n) {
        cout << "NO" << "\n";
        return;
    }
    for (char sign: result) {
        cout << sign << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        sequence.push_back(number);
    }
    solve();
    return 0;
}
