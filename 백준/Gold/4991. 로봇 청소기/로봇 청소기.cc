#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

/*
    방이 있을 때, 더러운 칸을 모두 깨끗한 칸으로 만들어야 함 -> 이 때 필요한 이동 횟수의 최소
    DFS로 처리하는 것 말이 안됨
    방향별 BFS? -> BFS는 시작 위치가 고정되어야 함. 그렇다고 이동마다 BFS를 돌리는 것도 말이 안됨
    미리 계산해두기
*/
struct Point {
    int r, c;
    Point(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

const int INF = 1e9 + 7;
int w, h;
char room[20][20];
int dist[11][11];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int bfs(Point x, Point y) {
    vector<vector<int>> cost(20, vector<int>(20, -1));
    queue<Point> q;
    cost[x.r][x.c] = 0;
    q.push(x);

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            Point next = Point(cur.r + dr[i], cur.c + dc[i]);
            if (!(next.r >= 0 && next.r < h && next.c >= 0 && next.c < w)) continue;
            if (room[next.r][next.c] == 'x') continue;
            if (cost[next.r][next.c] != -1) continue;
            cost[next.r][next.c] = cost[cur.r][cur.c] + 1;
            if (next.r == y.r && next.c == y.c) return cost[next.r][next.c];
            q.push(next);
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> w >> h && (!(w == 0 && h == 0))) {
        vector<Point> target;
        bool possible = true;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> room[i][j];
                if (room[i][j] == 'o') {
                    target.insert(target.begin(), Point(i, j));
                }
                else if (room[i][j] == '*') {
                    target.push_back(Point(i, j));
                }
            }
        }

        int T = target.size();
        for (int i = 0; i < T; i++) {
            for (int j = i + 1; j < T; j++) {
                int d = bfs(target[i], target[j]);
                if (d == -1) {
                    possible = false;
                    break;
                }
                dist[i][j] = dist[j][i] = d;
            }
        }
        if (!possible) {
            cout << -1 << "\n";
            continue;
        }

        vector<vector<int>> dp(T, vector<int>((1 << T), INF));
        dp[0][1] = 0;

        for (int mask = 1; mask < (1 << T); mask++) {
            for (int cur = 0; cur < T; cur++) {
                if (!(mask & (1 << cur))) continue;
                if (dp[cur][mask] == INF) continue;

                for (int next = 0; next < T; next++) {
                    if (mask & (1 << next)) continue;
                    int next_mask = mask | (1 << next);
                    dp[next][next_mask] = min(dp[next][next_mask], dp[cur][mask] + dist[cur][next]);
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < T; i++) {
            ans = min(ans, dp[i][(1 << T) - 1]);
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    
    return 0;
}