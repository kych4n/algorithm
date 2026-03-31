#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

/*
    'C'로 표시되어 있는 두 칸을 연결하기 위해 설치해야 하는 거울의 최솟값
    - 거울을 설치한다 = 이전 이동 방향에서 왼쪽 90도 또는 오른쪽 90도
    - 거울 사용 개수를 기준으로 하는 다익스트라
    - r, c, d
*/

struct Laser {
    int r, c, d;
    Laser(int r, int c, int d) {
        this->r = r;
        this->c = c;
        this->d = d;
    }
};

const int INF = 1e9 + 7;
int W, H;
char board[100][100];
int mirror[100][100][4];
deque<Laser> q;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
// -1 왼쪽, +1 오른쪽

pair<int, int> start = { -1, -1 };
pair<int, int> endd = { -1, -1 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> W >> H;
    string row;
    for (int i = 0; i < H; i++) {
        cin >> row;
        for (int j = 0; j < W; j++) {
            board[i][j] = row[j];
            if (board[i][j] == 'C') {
                if (start.first == -1) {
                    start = { i, j };
                }
                else {
                    endd = { i, j };
                }
            }
            for (int k = 0; k < 4; k++) {
                mirror[i][j][k] = INF;
            }
        }
    }

    for (int d = 0; d < 4; d++) {
        mirror[start.first][start.second][d] = 0;
        q.push_front(Laser(start.first, start.second, d));
    }

    while (!q.empty()) {
        Laser laser = q.front();
        q.pop_front();
        for (int next_d = 0; next_d < 4; next_d++) {
            int next_r = laser.r + dr[next_d];
            int next_c = laser.c + dc[next_d];
            if (!(next_r >= 0 && next_r < H && next_c >= 0 && next_c < W)) continue;
            if (board[next_r][next_c] == '*') continue;
            if (abs(laser.d - next_d) == 2) continue;

            int next_mirror = mirror[laser.r][laser.c][laser.d];
            if (next_d != laser.d) next_mirror += 1;

            if (mirror[next_r][next_c][next_d] > next_mirror) {
                mirror[next_r][next_c][next_d] = next_mirror;

                if (next_d != laser.d) {
                    q.push_back(Laser(next_r, next_c, next_d));
                }
                else {
                    q.push_front(Laser(next_r, next_c, next_d));
                }
            }
        }
    }

    int ans = INF;
    for (int d = 0; d < 4; d++) {
        ans = min(ans, mirror[endd.first][endd.second][d]);
    }
    cout << ans << "\n";

    return 0;
}