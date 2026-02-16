#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int cave[125][125];
int cost[125][125];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = 1e9 + 7;
        }
    }
}

bool is_in(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;

    while (true) {
        t++;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];
            }
        }
        init();

        queue<pair<int, int>> q;
        q.push({ 0,0 });
        cost[0][0] = cave[0][0];

        while (!q.empty()) {
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int next_r = cur_r + dr[i];
                int next_c = cur_c + dc[i];
                if (!is_in(next_r, next_c)) continue;
                if (cost[next_r][next_c] > cost[cur_r][cur_c] + cave[next_r][next_c]) {
                    cost[next_r][next_c] = cost[cur_r][cur_c] + cave[next_r][next_c];
                    q.push({ next_r, next_c });
                }
            }
        }
        cout << "Problem " << t << ": " << cost[N - 1][N - 1] << "\n";
    }
    return 0;
}