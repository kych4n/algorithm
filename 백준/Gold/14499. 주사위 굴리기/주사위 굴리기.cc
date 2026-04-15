#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

/*
    [입력] 명령
    [출력] 이동할 때마다 주사위 윗 면에 있는 수
    
    - 주사위의 각 칸이 어떤 수를 가지고 있는지 저장해야 함
    - 이동 시 주사위의 각 칸이 어떻게 변하는가 -> 이동한 상태에서 6번이 0이 아니면 바닥으로 복사 + 6번은 0
*/

int N, M, x, y, K;
int board[20][20];
int dr[] = { -1,0,0,-1,1 };
int dc[] = { -1,1,-1,0,0 };
int dice[7];
int cmd;

void roll_east() {
    int temp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = temp;
}

void roll_west() {
    int temp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
}

void roll_north() {
    int temp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = temp;
}

void roll_south() {
    int temp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = temp;
}

void roll(int cmd) {
    if (cmd == 1) roll_east();
    else if (cmd == 2) roll_west();
    else if (cmd == 3) roll_north();
    else if (cmd == 4) roll_south();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 6; i++) dice[i] = 0;

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> cmd;
        if (!(x + dr[cmd] >= 0 && x + dr[cmd] < N && y + dc[cmd] >= 0 && y + dc[cmd] < M)) {
            continue;
        }
        x += dr[cmd];
        y += dc[cmd];
        roll(cmd);
        if (board[x][y] == 0) {
            board[x][y] = dice[6];
        }
        else {
            dice[6] = board[x][y];
            board[x][y] = 0;
        }
        cout << dice[1] << "\n";
    }

    return 0;
}