#include <iostream>
#include <vector>
using namespace std;

int n, m, result = 1e9+7;
string start_w = "WBWBWBWB";
string start_b = "BWBWBWBW";
vector<vector<char>> board(50, vector<char>(50));

int solve(int start_row, int start_col) {
    int start_w_result = 0;
    int start_b_result = 0;
    for (int i=start_row; i<start_row+8; i++) {
        if (i % 2 == 0) {
            for (int j=0; j<8; j++) {
                if (board[i][start_col+j] != start_w[j]) {
                    start_w_result += 1;
                }
                if (board[i][start_col+j] != start_b[j]) {
                    start_b_result += 1;
                }
            }
        } else {
            for (int j=0; j<8; j++) {
                if (board[i][start_col+j] != start_b[j]) {
                    start_w_result += 1;
                }
                if (board[i][start_col+j] != start_w[j]) {
                    start_b_result += 1;
                }
            }
        }
    }
    return min(start_w_result, start_b_result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<=n-8; i++) {
        for (int j=0; j<=m-8; j++) {
            result = min(result, solve(i, j));
        }
    }

    cout << result << "\n";

    return 0;
}