#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    게임판은 3×3 격자판이며, 처음에는 비어 있다. 
    두 사람은 각각 X 또는 O 말을 번갈아가며 놓는데, 반드시 첫 번째 사람이 X를 놓고 두 번째 사람이 O를 놓는다. 
    어느 때든지 한 사람의 말이 가로, 세로, 대각선 방향으로 3칸을 잇는 데 성공하면 게임은 즉시 끝난다. 게임판이 가득 차도 게임은 끝난다.
    게임판의 상태가 주어지면, 그 상태가 틱택토 게임에서 발생할 수 있는 최종 상태인지를 판별하시오.

    최종 상태
    - X가 가로, 세로, 대각선 방향으로 3칸 -> 겹치지 않고 3칸 조합을 만드는 것은 불가능
    - O가 3칸 + X가 3칸인 것이 없어야 함

    최종 상태가 아닌 것
    - X의 개수 < O의 개수
    - X의 개수 == O의 개수 && X가 이미 3칸
    - X의 개수 > O의 개수 + 1
    - X의 개수 == O의 개수 + 1&& O가 이미 3칸
    - X의 개수 + O의 개수 < 9 && 3칸을 이루는 것이 없음

    1. 3칸 이루는지 찾는 함수
    2. 각각 개수 구하는 함수
*/
char board[3][3];
string tc;
int x, o;

bool is_three(char target) {
    return ((target == board[0][0]) && (target == board[0][1]) && (target == board[0][2])) ||
        ((target == board[1][0]) && (target == board[1][1]) && (target == board[1][2])) ||
        ((target == board[2][0]) && (target == board[2][1]) && (target == board[2][2])) ||
        ((target == board[0][0]) && (target == board[1][0]) && (target == board[2][0])) ||
        ((target == board[0][1]) && (target == board[1][1]) && (target == board[2][1])) ||
        ((target == board[0][2]) && (target == board[1][2]) && (target == board[2][2])) ||
        ((target == board[0][0]) && (target == board[1][1]) && (target == board[2][2])) ||
        ((target == board[0][2]) && (target == board[1][1]) && (target == board[2][0]));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> tc;
        if (tc == "end") break;
        x = 0, o = 0;
        for (int i = 0; i < 9; i++) {
            board[i / 3][i % 3] = tc[i];
            if (tc[i] == 'X') x++;
            else if (tc[i] == 'O') o++;
        }

        bool xthree = is_three('X');
        bool othree = is_three('O');
        if ((x < o)
            || (x == o && xthree)
            || (x > o + 1)
            || (x == o + 1 && othree)
            || (x+o < 9 && !xthree && !othree)
            ) {
            cout << "invalid\n";
        }
        else {
            cout << "valid\n";
        }
    }

    return 0;
}