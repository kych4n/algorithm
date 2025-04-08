#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, m;
map<string, string> save;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    string site, password;
    for (int i = 0; i < n; i++) {
        cin >> site >> password;
        save[site] = password;
    }
    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << save[site] << "\n";
    }
    return 0;
}
