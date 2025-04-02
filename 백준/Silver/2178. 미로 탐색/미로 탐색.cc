#include <iostream>
#include <queue>
using namespace std;

vector<string> maze;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solve(int n, int m) {
    vector<vector<int> > minCount(n, vector<int>(m, 1e9 + 7));
    minCount[0][0] = 1;
    queue<pair<int, int> > q;
    q.push({0, 0});
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if ((newY >= 0 && newY < n && newX >= 0 && newX < m) && (maze[newY][newX] == '1') && (
                    minCount[curY][curX] + 1 < minCount[newY][newX])) {
                minCount[newY][newX] = minCount[curY][curX] + 1;
                q.push({newY, newX});
            }
        }
    }
    return minCount[n - 1][m - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string row;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> row;
        maze.push_back(row);
    }
    cout << solve(n, m) << "\n";
    return 0;
}
