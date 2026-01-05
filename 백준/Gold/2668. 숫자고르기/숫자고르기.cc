#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers(101);
set<int> s;

void dfs(vector<int>& current, vector<bool>& visited) {
    if (visited[current.back()]) {
        if (current.front() == current.back()) {
            for (int c : current) {
                s.insert(c);
            }
        }
        return;
    }
    visited[current.back()] = true;
    current.push_back(numbers[current.back()]);
    dfs(current, visited);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    for (int start = 1; start <= N; start++) {
        if (start == numbers[start]) {
            s.insert(start);
            continue;
        }
        vector<bool> visited(101);
        vector<int> current;
        current.push_back(start);
        dfs(current, visited);
    }

    cout << s.size() << "\n";
    for (int n : s) {
        cout << n << "\n";
    }
    return 0;
}