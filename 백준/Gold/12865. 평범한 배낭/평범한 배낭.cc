#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int w, v;
};
int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].w >> items[i].v;
    }

    vector<int> bag(K + 1);
    for (const Item& item : items) {
        for (int i = K; i > item.w; i--) {
            if (bag[i - item.w] != 0) {
                bag[i] = max(bag[i], bag[i - item.w] + item.v);
            }
        }
        bag[item.w] = max(bag[item.w], item.v);
    }

    int max_value = 0;
    for (int i = 0; i <= K; i++) {
        max_value = max(max_value, bag[i]);
    }
    cout << max_value << "\n";
    return 0;
}