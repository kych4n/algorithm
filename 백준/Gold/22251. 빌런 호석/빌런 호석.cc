#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

/*
    - 최소 1개, 최대 P개 반전
    - 최종 결과는 1 이상 N 이하
    - 수는 0으로 시작할 수 있음
    - 현재 X층에 멈춰있음

    [필요한 것]
    - 반전해야할 개수
    - 현재 수, 변경 시도할 자릿수, 현재 플롭카운트
*/

int plop[10][10];
int digit[10] = {
    0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011
};

int N, K, P, X;
int result = 0;

void try_plop(int cur_number, int cur_digit, int cur_plop_count) {
    if (cur_digit == K) {
        if (cur_number >= 1 && cur_number <= N && cur_plop_count >= 1 && cur_plop_count <= P) {
            result++;
        }
        return;
    }
    int div = 1;
    for (int i = 0; i < cur_digit; i++) div *= 10;
    int target_digit_number = cur_number / div % 10;
    for (int i = 0; i < 10; i++) {
        if (cur_plop_count + plop[target_digit_number][i] <= P) {
            try_plop(cur_number - target_digit_number * div + i * div, 
                cur_digit + 1, 
                cur_plop_count + plop[target_digit_number][i]);
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            plop[i][j] = bitset<7>(digit[i] ^ digit[j]).count();
        }
    }

    cin >> N >> K >> P >> X;

    try_plop(X, 0, 0);

    cout << result << "\n";

    return 0;
}