#include <iostream>
#include <vector>
using namespace std;

int t, n, MAX_VALUE = 40;
vector<pair<int, int> > fibonacci(MAX_VALUE + 1);

void solve() {
    fibonacci[0].first = 1;
    fibonacci[1].second = 1;
    for (int i = 2; i <= MAX_VALUE; i++) {
        fibonacci[i].first += (fibonacci[i - 2].first + fibonacci[i - 1].first);
        fibonacci[i].second += (fibonacci[i - 2].second + fibonacci[i - 1].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << fibonacci[n].first << " " << fibonacci[n].second << "\n";
    }
    return 0;
}
