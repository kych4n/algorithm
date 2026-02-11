#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    vector<int> value(N);
    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }

    int left = 0, right = N - 1, min_value = INT32_MAX;
    pair<int, int> comb;
    while (left < right) {
        int mix_value = value[left] + value[right];
        if (min_value > abs(mix_value)) {
            min_value = abs(mix_value);
            comb = { value[left], value[right] };
        }
        if (mix_value > 0) {
            right--;
        }
        else if (mix_value < 0) {
            left++;
        }
        else {
            break;
        }
    }

    cout << comb.first << " " << comb.second << "\n";
    
    return 0;
}