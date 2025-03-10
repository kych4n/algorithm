#include <iostream>
#include <queue>
using namespace std;

int t, n, m, document;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int i = 0; i < t; i++) {
        priority_queue<int> documents_by_importance;
        queue<pair<int, int> > documents_by_inserted_order;
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> document;
            documents_by_importance.push(document);
            documents_by_inserted_order.emplace(document, j);
        }
        while (!documents_by_importance.empty()) {
            if (documents_by_importance.top() > documents_by_inserted_order.front().first) {
                documents_by_inserted_order.push(documents_by_inserted_order.front());
                documents_by_inserted_order.pop();
            } else {
                if (documents_by_inserted_order.front().second == m) {
                    cout << n - documents_by_importance.size() + 1 << "\n";
                    break;
                }
                documents_by_importance.pop();
                documents_by_inserted_order.pop();
            }
        }
    }

    return 0;
}
