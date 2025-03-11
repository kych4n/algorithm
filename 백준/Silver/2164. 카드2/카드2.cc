#include <iostream>
#include <queue>
using namespace std;

int solve(int n) {
    queue<int> cards;
    bool need_push = false;
    for (int i = 1; i <= n; i++) {
        cards.push(i);
    }
    while (cards.size() > 1) {
        if (need_push) {
            cards.push(cards.front());
        }
        cards.pop();
        need_push = !need_push;
    }
    return cards.front();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << "\n";

    return 0;
}
