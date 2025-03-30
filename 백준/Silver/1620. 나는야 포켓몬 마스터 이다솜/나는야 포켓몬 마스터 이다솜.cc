#include <iostream>
#include <map>
using namespace std;

map<string, string> book;

void getInput(int n) {
    string name;
    for (int number = 1; number <= n; number++) {
        cin >> name;
        book[name] = to_string(number);
        book[to_string(number)] = name;
    }
}

void solve(int m) {
    string query;
    for (int i = 0; i < m; i++) {
        cin >> query;
        cout << book[query] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    getInput(n);
    solve(m);
    return 0;
}
