#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, number;
vector<int> numbers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> number;
        int start = lower_bound(numbers.begin(), numbers.end(), number) - numbers.begin();
        int end = upper_bound(numbers.begin(), numbers.end(), number) - numbers.begin();
        cout << end - start << " ";
    }
    return 0;
}
