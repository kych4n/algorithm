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
    stack<int> row_s;
    // 상하좌우
    if (dir == 0) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                if (board[i][j] == 0) continue;
                if (s.empty()) {
                    s.push(board[i][j]);
                }
                else {
                    if (s.top() == board[i][j]) {
                        s.top() *= 2;
                        s.push(0);
                    }
                    else {
                        s.push(board[i][j]);
                    }
                }
            }
            while (!s.empty()) {
                if (s.top() != 0) {
                    row_s.push(s.top());
                }
                s.pop();
            }
            for (int i = 0; i < N; i++) {
                if (!row_s.empty()) {
                    board[i][j] = row_s.top();
                    row_s.pop();
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
    else if (dir == 1) {
        for (int j = 0; j < N; j++) {
            for (int i = N - 1; i >= 0; i--) {
                if (board[i][j] == 0) continue;
                if (s.empty()) {
                    s.push(board[i][j]);
                }
                else {
                    if (s.top() == board[i][j]) {
                        s.top() *= 2;
                        s.push(0);
                    }
                    else {
                        s.push(board[i][j]);
                    }
                }
            }
            while (!s.empty()) {
                if (s.top() != 0) {
                    row_s.push(s.top());
                }
                s.pop();
            }
            for (int i = N - 1; i >= 0; i--) {
                if (!row_s.empty()) {
                    board[i][j] = row_s.top();
                    row_s.pop();
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) continue;
                if (s.empty()) {
                    s.push(board[i][j]);
                }
                else {
                    if (s.top() == board[i][j]) {
                        s.top() *= 2;
                        s.push(0);
                    }
                    else {
                        s.push(board[i][j]);
                    }
                }
            }
            while (!s.empty()) {
                if (s.top() != 0) {
                    row_s.push(s.top());
                }
                s.pop();
            }
            for (int j = 0; j < N; j++) {
                if (!row_s.empty()) {
                    board[i][j] = row_s.top();
                    row_s.pop();
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
    else if (dir == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j] == 0) continue;
                if (s.empty()) {
                    s.push(board[i][j]);
                }
                else {
                    if (s.top() == board[i][j]) {
                        s.top() *= 2;
                        s.push(0);
                    }
                    else {
                        s.push(board[i][j]);
                    }
                }
            }
            while (!s.empty()) {
                if (s.top() != 0) {
                    row_s.push(s.top());
                }
                s.pop();
            }
            for (int j = N - 1; j >= 0; j--) {
                if (!row_s.empty()) {
                    board[i][j] = row_s.top();
                    row_s.pop();
                }
                else {
                    board[i][j] = 0;
                }
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