#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    커서 근방에서 작업이 이루어짐 -> 스택
    - L : 왼쪽의 마지막을 오른쪽 스택에 추가
    - D : 오른쪽의 마지막을 왼쪽 스택에 추가
    - B : 비어있지 않다면 왼쪽의 마지막을 삭제
    - P : 왼쪽의 마지막에 추가
*/

string cursor_left, cursor_right = "";
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> cursor_left >> M;
    N = cursor_left.length();

    while (M--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cursor_left.empty()) continue;
            cursor_right.push_back(cursor_left.back());
            cursor_left.pop_back();
        }
        else if (cmd == 'D') {
            if (cursor_right.empty()) continue;
            cursor_left.push_back(cursor_right.back());
            cursor_right.pop_back();
        }
        else if (cmd == 'B') {
            if (cursor_left.empty()) continue;
            cursor_left.pop_back();
        }
        else if (cmd == 'P') {
            char c;
            cin >> c;
            cursor_left.push_back(c);
        }
    }

    reverse(cursor_right.begin(), cursor_right.end());
    cout << cursor_left + cursor_right << "\n";

    return 0;
}