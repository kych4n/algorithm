#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int lower_bound = 0;
    int upper_bound = v.back() - v.front();
    while (lower_bound <= upper_bound) {
        int target_distance = (lower_bound + upper_bound) / 2;
        int installed_count = 1;
        int last_point = 0;
        for (int i = 1; i < N; i++) {
            if (v[i] - v[last_point] >= target_distance) {
                installed_count++;
                last_point = i;
            }
        }
        if (installed_count >= C) {
            result = max(result, target_distance);
            lower_bound = target_distance + 1;
        }
        else if (installed_count < C) {
            upper_bound = target_distance - 1;
        }
    }

    cout << result << "\n";

    return 0;
}