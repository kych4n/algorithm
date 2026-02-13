#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

int N, K, P, X, result = 0;
int target_digits[10];
int flip_count[10][10];
int bit[10] = {
    0b1111110,
    0b0110000,
    0b1101101,
    0b1111001,
    0b0110011,
    0b1011011,
    0b1011111,
    0b1110000,
    0b1111111,
    0b1111011
};

void flip(int cur_number, int cur_idx, int cur_p) {
    if (cur_p > P) {
        return;
    }
    if (cur_idx == K) {
        if (cur_p >= 1 && cur_p <= P && cur_number >= 1 && cur_number <= N) {
            result++;
        }
        return;
    }

    for (int after = 0; after <= 9; after++) {
        int next_p = cur_p + flip_count[target_digits[cur_idx]][after];
        flip(cur_number * 10 + after, cur_idx + 1, next_p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            flip_count[i][j] = bitset<7>(bit[i] ^ bit[j]).count();
        }
    }

    cin >> N >> K >> P >> X;
    int temp_x = X;
    for (int i = K - 1; i >= 0; i--) {
        target_digits[i] = temp_x % 10;
        temp_x /= 10;
    }
    
    flip(0, 0, 0);

    cout << result << "\n";

    return 0;
}