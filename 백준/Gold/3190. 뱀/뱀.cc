#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
    뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

    먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
    만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
    만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
    만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
    사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.

    - 뱀의 몸통 - 덱
    - 사과 - 보드
    - 방향 변환 정보 - 큐
*/

struct Change {
    int when;
    char direction;
    Change(int when, char direction) {
        this->when = when;
        this->direction = direction;
    }
};

struct Body {
    int r, c;
    Body(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

int N, K, L;
bool apple[100][100];
queue<Change> change;
int cur_sec = 0;
int cur_dir = 1;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

bool is_end = false;

deque<Body> snake;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int k = 0; k < K; k++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        apple[r][c] = true;
    }

    cin >> L;
    for (int l = 0; l < L; l++) {
        int when; char direction;
        cin >> when >> direction;
        change.push(Change(when, direction));
    }

    snake.push_back(Body(0, 0));

    while (!is_end) {
        cur_sec++;
        Body head = snake.front();
        Body next = Body(head.r + dr[cur_dir], head.c + dc[cur_dir]);
        if (!(next.r >= 0 && next.r < N && next.c >= 0 && next.c < N)) is_end = true;
        for (const Body& body : snake) {
            if (body.r == next.r && body.c == next.c) {
                is_end = true;
                break;
            }
        }
        if (is_end) {
            cout << cur_sec << "\n";
            break;
        }
        if (apple[next.r][next.c]) {
            apple[next.r][next.c] = false;
        }
        else {
            snake.pop_back();
        }
        snake.push_front(next);

        if (change.empty()) continue;
        if (change.front().when == cur_sec) {
            if (change.front().direction == 'L') {
                cur_dir -= 1;
                if (cur_dir < 0) cur_dir += 4;
            }
            else {
                cur_dir += 1;
                cur_dir %= 4;
            }
            change.pop();
        }
    }
    
    return 0;
}