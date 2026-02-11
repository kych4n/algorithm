#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> S;
    vector<int> number(N);
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }
    
    int left = 0, right = 0;
    int cur_sum = number[left];
    int min_length = 1e9 + 7;
    while (left <= right && right < N) {
        if (cur_sum < S) {
            if (right == N - 1) break;
            cur_sum += number[++right];
        }
        else if (cur_sum > S) {
            min_length = min(min_length, right - left + 1);
            cur_sum -= number[left++];
        }
        else {
            min_length = min(min_length, right - left + 1);
            if (right == N - 1) break;
            cur_sum += number[++right];
        }
    }
    
    if (min_length == 1e9 + 7) {
        cout << 0 << "\n";
    }
    else {
        cout << min_length << "\n";
    }
    return 0;
}