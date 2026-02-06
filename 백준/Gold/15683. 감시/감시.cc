#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CCTV {
    int type, r, c;
};

int N, M, result = 64;
int board[8][8];
vector<CCTV> cctvs;

// 상, 우, 하, 좌 (시계 방향)
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

// 각 CCTV 타입별 감시 방향 (0:상, 1:우, 2:하, 3:좌)
vector<vector<int>> get_directions(int type) {
    if (type == 1) return { {0}, {1}, {2}, {3} };
    if (type == 2) return { {0, 2}, {1, 3} };
    if (type == 3) return { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
    if (type == 4) return { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} };
    return { {0, 1, 2, 3} }; // type 5
}

// 특정 방향으로 감시 영역 표시 (# 대신 -1 사용)
void watch(int r, int c, int dir, int tmp[8][8]) {
    int nr = r, nc = c;
    while (true) {
        nr += dr[dir];
        nc += dc[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || tmp[nr][nc] == 6) break;
        if (tmp[nr][nc] == 0) tmp[nr][nc] = -1; // 빈칸만 표시
    }
}

void solve(int idx, int cur_board[8][8]) {
    if (idx == cctvs.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (cur_board[i][j] == 0) cnt++;
        result = min(result, cnt);
        return;
    }

    int r = cctvs[idx].r;
    int c = cctvs[idx].c;
    int type = cctvs[idx].type;

    // 현재 CCTV가 가질 수 있는 모든 방향 조합 순회
    for (auto& dirs : get_directions(type)) {
        int next_board[8][8];
        // 배열 복사
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                next_board[i][j] = cur_board[i][j];

        // 해당 방향들 감시 표시
        for (int d : dirs) watch(r, c, d, next_board);

        // 다음 CCTV로 진행
        solve(idx + 1, next_board);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5)
                cctvs.push_back({ board[i][j], i, j });
        }
    }

    solve(0, board);
    cout << result << "\n";

    return 0;
}