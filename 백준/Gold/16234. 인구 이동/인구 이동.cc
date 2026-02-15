#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, L, R, day = 0;
int board[50][50];
bool visited[50][50];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
bool is_moved = false;

void init() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            visited[i][j] = false;
        }
    }

    is_moved = false;
}

bool is_in(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

bool is_unionable(int a, int b) {
    return abs(a - b) >= L && abs(a - b) <= R;
}

void unionize(int r, int c) {
    vector<pair<int, int>> union_country;
    queue<pair<int, int>> q;

    int val = board[r][c];
    visited[r][c] = true;
    union_country.push_back({ r, c });
    q.push({ r,c });
    
    while (!q.empty()) {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            if (!is_in(next_r, next_c)) continue;
            if (visited[next_r][next_c]) continue;
            if (!(is_unionable(board[cur_r][cur_c], board[next_r][next_c]))) continue;
            visited[next_r][next_c] = true;
            union_country.push_back({ next_r, next_c });
            q.push({ next_r, next_c });
            val += board[next_r][next_c];
        }
    }

    int union_count = union_country.size();

    if (union_count > 1) {
        is_moved = true;
        for (pair<int, int>& p : union_country) {
            board[p.first][p.second] = val / union_count;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        init();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    unionize(i, j);
                }
            }
        }

        if (!is_moved) break;
        day++;
    }

    cout << day << "\n";

    return 0;
}