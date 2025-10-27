#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool check_mate(const vector<vector<char>>& board, char target) {
    return (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == target) || (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == target) || (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == target)
        || (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == target) || (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == target) || (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == target)
        || (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] == target) || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == target);
}

bool game() {
    string str;
    cin >> str;
    if (str == "end") {
        return false;
    }
    vector<vector<char>> board(3, vector<char>(3));
    int x_count = 0;
    int o_count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = str[i * 3 + j];
            if (board[i][j] == 'X') {
                x_count += 1;
            }
            else if (board[i][j] == 'O') {
                o_count += 1;
            }
        }
    }
    // invalid

    bool x_check = check_mate(board, 'X');
    bool o_check = check_mate(board, 'O');
    bool double_check = x_check && o_check;

    if (x_count - o_count > 1 || x_count < o_count || double_check || (!(x_check || o_check) && x_count+o_count < 9 || (!x_check && o_check && x_count > o_count) || (x_check && !o_check && x_count <= o_count))) {
        cout << "invalid\n";
    }
    else {
        cout << "valid\n";
    }

    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        if (!game()) {
            break;
        }
    }

    return 0;
}