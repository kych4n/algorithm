#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    빨간공 왼/오
    파란공 왼/오

    내가 target을 오른쪽에 두려고 함
    오른쪽에서 왼쪽으로 가다가 target이 아닌 것이 나오면 이후에 target이 나왔을 때 건너뛰는 것이 필요함
*/

int N, result = 1e9 + 7;
string str;

void move_right(char target) {
    bool need_move = false;
    int temp_result = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (target != str[i]) {
            need_move = true;
        }
        else if (need_move) {
            temp_result += 1;
        }
    }
    result = min(result, temp_result);
}

void move_left(char target) {
    bool need_move = false;
    int temp_result = 0;
    for (int i = 0; i < N; i++) {
        if (target != str[i]) {
            need_move = true;
        }
        else if (need_move) {
            temp_result += 1;
        }
    }
    result = min(result, temp_result);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> str;
    move_left('B');
    move_left('R');
    move_right('B');
    move_right('R');

    cout << result << "\n";

    return 0;
}