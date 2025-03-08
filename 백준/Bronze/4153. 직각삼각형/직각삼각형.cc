#include <iostream>
#include <queue>
using namespace std;

int a, b, c;

bool is_right_triangle(int a, int b, int c) {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    c = pq.top();
    pq.pop();
    if (a * a + b * b == c * c) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        if (is_right_triangle(a, b, c)) {
            cout << "right" << "\n";
        } else {
            cout << "wrong" << "\n";
        }
    }
    return 0;
}
