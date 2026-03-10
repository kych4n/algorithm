#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    CCTV가 주어질 때, 사각지대의 최소 크기를 구하기
    - 딱히 규칙은 없으므로 다 해봐야 함
    - CCTV의 위치는 고정되지만 방향은 바꿀 수 있음
    - CCTV를 하나씩 순회하면서 방향 바꾸기 -> 현재 cctv idx(총 cctv 개수와 같으면 종료), 복사해서 사용
    - CCTV의 한 방향 케이스에서 처리하고 넘기기
*/

struct CCTV {
    int number, r, c;
};

int N, M, result = 1e9 + 7;
vector<vector<int>> office(8, vector<int>(8));
vector<CCTV> cctv;
vector<pair<int, int>> direction = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

vector<vector<int>> get_direction_idx(int number) {
    if (number == 1) return { {0}, {1}, {2}, {3} };
    else if (number == 2) return { {0, 2}, {1, 3} };
    else if (number == 3) return { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
    else if (number == 4) return { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} };
    else return { {0,1,2,3} };
}

void supervise(int cur_idx, vector<vector<int>> cur_office) {
    if (cur_idx == cctv.size()) {
        int temp_result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cur_office[i][j] == 0) {
                    temp_result += 1;
                }
            }
        }
        result = min(result, temp_result);
        return;
    }

    CCTV cur_cctv = cctv[cur_idx];
    vector<vector<int>> new_office;
    vector<vector<int>> direction_idx = get_direction_idx(cur_cctv.number);
    for (const vector<int>& dirs : direction_idx) {
        new_office = cur_office;
        for (const int dir : dirs) {
            int r = cur_cctv.r;
            int c = cur_cctv.c;
            while (true) {
                r += direction[dir].first;
                c += direction[dir].second;
                if (!(r >= 0 && r < N && c >= 0 && c < M)) break;
                if (new_office[r][c] == 6) break;
                if (new_office[r][c] == 0) new_office[r][c] = -1;
            }
        }
        supervise(cur_idx + 1, new_office);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                cctv.push_back({ office[i][j], i, j });
            }
        }
    }

    supervise(0, office);
    cout << result << "\n";

    return 0;
}