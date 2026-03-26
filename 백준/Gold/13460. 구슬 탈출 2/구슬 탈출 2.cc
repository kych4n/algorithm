#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
    재귀 - 현재 횟수(10 넘기면 종료하기 위함), 방향(이동) 


    - 방향에 따라 먼저 움직이는 것 결정
    - 좌로 움직여야 한다 -> c가 더 작은 것
    - 우로 움직여야 한다 -> c가 더 큰 것
    - 위로 움직여야 한다 -> r가 더 작은 것
    - 아래로 움직여야 한다 -> r가 더 큰 것
*/

int N, M;
char board[10][10];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int result = 1e9 + 7;

struct Bead {
    int r, c;
    Bead() {
    };
    Bead(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

Bead red, blue;

bool red_is_first(const Bead& red, const Bead& blue, int dir) {
    if (dir == 0) {
        if (red.r < blue.r) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (dir == 1) {
        if (red.r > blue.r) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (dir == 2) {
        if (red.c < blue.c) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (dir == 3) {
        if (red.c > blue.c) {
            return true;
        }
        else {
            return false;
        }
    }
}

void roll(int count, int dir, Bead red, Bead blue) {
    if (count > 10) return;
    bool b = red_is_first(red, blue, dir);
    Bead first, second;
    if (b) {
        first = red;
        second = blue;
    }
    else {
        first = blue;
        second = red;
    }
    bool red_out = false;

    // first
    while (true) {
        if (board[first.r + dr[dir]][first.c + dc[dir]] == '#') break;
        if (board[first.r + dr[dir]][first.c + dc[dir]] == 'O') {
            // red
            if (b) {
                first.r = -1;
                first.c = -1;
                red_out = true;
                break;
            }
            // blue
            else {
                return;
            }
        }
        first.r += dr[dir];
        first.c += dc[dir];
    }
    // second
    while (true) {
        if (board[second.r + dr[dir]][second.c + dc[dir]] == '#') break;
        if (second.r + dr[dir] == first.r && second.c + dc[dir] == first.c) break;
        if (board[second.r + dr[dir]][second.c + dc[dir]] == 'O') {
            // red
            if (!b) {
                red_out = true;
                break;
            }
            // blue
            else {
                return;
            }
        }
        second.r += dr[dir];
        second.c += dc[dir];
    }

    if (red_out) {
        result = min(result, count);
        return;
    }
    if (b) {
        red = first;
        blue = second;
    }
    else {
        red = second;
        blue = first;
    }

    for (int next_dir = 0; next_dir < 4; next_dir++) {
        if (dir == next_dir) continue;
        roll(count + 1, next_dir, red, blue);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j];
            if (board[i][j] == 'R') {
                red = Bead(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                blue = Bead(i, j);
                board[i][j] = '.';
            }
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        roll(1, dir, red, blue);
    }
    if (result == 1e9 + 7) result = -1;
    cout << result << "\n";
    
    return 0;
}