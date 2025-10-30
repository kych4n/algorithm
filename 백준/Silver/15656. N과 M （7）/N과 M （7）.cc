#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;

void bt(vector<int>& current_permutation) {
    if (current_permutation.size() == M) {
        for (int number : current_permutation) {
            cout << number << " ";
        }
        cout << "\n";
        return;
    }
    for (int number : numbers) {
        current_permutation.push_back(number);
        bt(current_permutation);
        current_permutation.pop_back();
    }
}

void init() {
    cin >> N >> M;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    vector<int> current_permutation;
    bt(current_permutation);

    return 0;
}