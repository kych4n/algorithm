#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

/*
    [입력] 종이에 쓰여진 수
    [출력] 테트로미노를 놓았을 때, 합의 최대

    - 도형을 종류에 따라 회전하고 대칭하는 건 좀 말이 안됨
    - 백트래킹 : 현재 개수, 수의 합
*/

int N, M;
int paper[500][500];
bool visited[500][500];
int max_val = 0;
int result = 0;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bt(int x, int y, int count, int sum) {
    if (sum + (4 - count) * max_val <= result) return;

    if (count == 4) {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int new_x = x + dr[i];
        int new_y = y + dc[i];
        if (!(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M)) continue;
        if (visited[new_x][new_y]) continue;
        visited[new_x][new_y] = true;
        bt(new_x, new_y, count + 1, sum + paper[new_x][new_y]);
        visited[new_x][new_y] = false;
    }
}

void fxxx(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int temp_sum = paper[x][y];
        bool possible = true;
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;
            int new_x = x + dr[j];
            int new_y = y + dc[j];
            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M) {
                temp_sum += paper[new_x][new_y];
            }
            else {
                possible = false;
                break;
            }
        }
        if (possible) result = max(result, temp_sum);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
            max_val = max(max_val, paper[i][j]);
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            bt(i, j, 1, paper[i][j]);
            visited[i][j] = false;

            fxxx(i, j);
        }
    }

    cout << result << "\n";

    return 0;
}