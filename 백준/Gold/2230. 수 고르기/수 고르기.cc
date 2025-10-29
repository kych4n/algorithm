#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int N;
long long M;
long long result = 2e9;
vector<long long> A;

void init() {
    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    /*for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }*/
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(A.begin(), A.end(), A[i] + M);
        if (it != A.end()) {
            int idx = it - A.begin();
            result = min(result, A[idx] - A[i]);
        }
    }
    cout << result << "\n";

    return 0;
}