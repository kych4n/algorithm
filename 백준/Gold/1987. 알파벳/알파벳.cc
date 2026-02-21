#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, result = 1;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<string> board;
vector<bool> visited(26);

void bt(int cur_r, int cur_c, int temp_result) {
    for (int i = 0; i < 4; i++) {
        int new_r = cur_r + dr[i];
        int new_c = cur_c + dc[i];
        if (!(new_r >= 0 && new_r < R && new_c >= 0 && new_c < C)) continue;
        char new_char = board[new_r][new_c];
        if (!visited[new_char - 'A']) {
            visited[new_char - 'A'] = true;
            result = max(result, temp_result + 1);
            bt(new_r, new_c, temp_result + 1);
            visited[new_char - 'A'] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    visited[board[0][0] - 'A'] = true;
    bt(0, 0, 1);

    cout << result << "\n";

    return 0;
}