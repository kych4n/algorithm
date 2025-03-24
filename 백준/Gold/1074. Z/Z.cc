#include <complex>
#include <iostream>
using namespace std;

int n, r, c, result = 0;

void Z(int length, int start_r, int start_c) {
    if (length == 1 && r == start_r && c == start_c) {
        cout << result << "\n";
        return;
    }
    int half_length = length / 2;
    if (r < start_r + half_length && c < start_c + half_length) {
        Z(half_length, start_r, start_c);
        return;
    }
    result += half_length * half_length;
    if (r < start_r + half_length && c < start_c + length) {
        Z(half_length, start_r, start_c + half_length);
        return;
    }
    result += half_length * half_length;
    if (r < start_r + length && c < start_c + half_length) {
        Z(half_length, start_r + half_length, start_c);
        return;
    }
    result += half_length * half_length;
    if (r < start_r + length && c < start_c + length) {
        Z(half_length, start_r + half_length, start_c + half_length);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> c;
    Z(pow(2, n), 0, 0);
    return 0;
}
