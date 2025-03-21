#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n, m, k, x, y;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

vector<vector<int> > field(50, vector<int>(50));

void eat_by_worm(int start_y, int start_x) {
    queue<pair<int, int> > q;
    q.push({start_y, start_x});
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_y = cur_y + dy[i];
            int new_x = cur_x + dx[i];
            if ((new_y >= 0 && new_y < n && new_x >= 0 && new_x < m) && field[new_y][new_x]) {
                field[new_y][new_x] = 0;
                q.push({new_y, new_x});
            }
        }
    }
}

void set_init_field(int m, int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            field[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        field[y][x] = 1;
    }
}

int get_worm_count() {
    int worm_count = 0;
    for (int start_y = 0; start_y < n; start_y++) {
        for (int start_x = 0; start_x < m; start_x++) {
            if (field[start_y][start_x]) {
                worm_count += 1;
                eat_by_worm(start_y, start_x);
            }
        }
    }
    return worm_count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        set_init_field(m, n, k);
        cout << get_worm_count() << "\n";
    }
    return 0;
}
