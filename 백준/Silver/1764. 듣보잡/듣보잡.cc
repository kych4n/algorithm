#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve(int n, int m) {
    string notListen, notSeen;
    set<string> notListenAndNotSeen;
    vector<string> result;
    for (int i = 0; i < n; i++) {
        cin >> notListen;
        notListenAndNotSeen.insert(notListen);
    }
    for (int i = 0; i < m; i++) {
        cin >> notSeen;
        if (notListenAndNotSeen.find(notSeen) != notListenAndNotSeen.end()) {
            result.push_back(notSeen);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (string name: result) {
        cout << name << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}
