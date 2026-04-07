#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*

*/

struct Point {
    int r, c;
    Point() {

    }
    Point(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

int N, M;
int land[1000][1000];
int cost[1000][1000];
Point start;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
            if (land[i][j] == 2) {
                start = Point(i, j);
            }
            cost[i][j] = -1;
        }
    }
    
    queue<Point> q;
    q.push(start);
    cost[start.r][start.c] = 0;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point next = Point(cur.r + dr[i], cur.c + dc[i]);
            if (next.r >= 0 && next.r < N && next.c >= 0 && next.c < M && land[next.r][next.c] != 0 && cost[next.r][next.c] == -1) {
                cost[next.r][next.c] = cost[cur.r][cur.c] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (land[i][j] == 0) {
                cout << 0 << " ";
            }
            else {
                cout << cost[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}