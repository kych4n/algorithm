#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
    5번 이동해서 얻을 수 있는 가장 큰 불록 (4 * 100000)

    (방향, 보드, 이동 횟수)
    - 이동 횟수가 5이면, 최댓값 탐색
    - 이동 방향의 끝에서부터 하나씩 추가, 인접한 것과 합치기가 이루어지므로 스택
*/

int N, result = 0;

void move(int dir, vector<vector<int>> board, int move_count) {
    if (move_count > 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = max(result, board[i][j]);
            }
        }
        return;
    }

    stack<int> s;
    stack<int> line_s;

    int r, c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dir == 0) { r = j; c = i; }
            else if (dir == 1) { r = N - 1 - j; c = i; }
            else if (dir == 2) { r = i; c = j; }
            else if (dir == 3) { r = i; c = N - 1 - j; }

            if (board[r][c] == 0) continue;
            if (s.empty()) {
                s.push(board[r][c]);
            }
            else {
                if (s.top() == board[r][c]) {
                    s.top() *= 2;
                    s.push(-1);
                }
                else {
                    s.push(board[r][c]);
                }
            }
        }
        while (!s.empty()) {
            if (s.top() != -1) {
                line_s.push(s.top());
            }
            s.pop();
        }
        for (int j = 0; j < N; j++) {
            if (dir == 0) { r = j; c = i; }
            else if (dir == 1) { r = N - 1 - j; c = i; }
            else if (dir == 2) { r = i; c = j; }
            else if (dir == 3) { r = i; c = N - 1 - j; }

            if (!line_s.empty()) {
                board[r][c] = line_s.top();
                line_s.pop();
            }
            else {
                board[r][c] = 0;
            }
        }
    }

    for (int new_dir = 0; new_dir < 4; new_dir++) {
        move(new_dir, board, move_count + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        move(i, board, 1);
    }

    cout << result << "\n";

    return 0;
}