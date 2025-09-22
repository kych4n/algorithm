#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

string W;
int K, T;

pair<int, int> game(string W, int K) {
    vector<vector<int>> appearance_location(26);
    for (int i = 0; i < W.length(); i++) {
        appearance_location[(int)(W[i] - 'a')].push_back(i);
    }
    int game1_result = 1e9 + 7;
    int game2_result = 0;
    for (int i = 0; i < 26; i++) {
        int size = appearance_location[i].size();
        for (int j = 0; j <= size - K; j++) {
            int length = appearance_location[i][j + K - 1] - appearance_location[i][j] + 1;
            game1_result = min(game1_result, length);
            game2_result = max(game2_result, length);
        }
    }
    if (game1_result == 1e9 + 7) {
        game1_result = -1;
    }

    if (game2_result == 0) {
        game2_result = -1;
    }
    return make_pair(game1_result, game2_result);
}

int main() {
    cin >> T;
    for (int u = 0; u < T; u++) {
        cin >> W >> K;
        pair<int, int> result = game(W, K);
        if (result.first == -1) {
            cout << -1 << "\n";
        }
        else {
            cout << result.first << " " << result.second << "\n";
        }
    }
    return 0;
}