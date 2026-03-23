#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, K;
int IN = 0, OUT;

struct Block {
    int life; bool robot_on = false;
};

/*  
    로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.
    1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    2-1. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
    3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
    4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    OUT = N - 1;

    deque<Block> belt(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> belt[i].life;
    }

    int unavailable_count = 0;
    int stage = 0;
    
    while (true) {
        stage++;

        // #1
        belt.push_front(belt.back());
        belt.pop_back();
        belt[OUT].robot_on = false;

        // #2
        for (int i = OUT - 1; i >= 0; i--) {
            if (belt[i].robot_on && belt[i + 1].life > 0 && !belt[i + 1].robot_on) {
                belt[i].robot_on = false;

                belt[i + 1].life--;
                if (belt[i + 1].life == 0) unavailable_count++;
                belt[i + 1].robot_on = true;
            }
        }
        belt[OUT].robot_on = false;

        // #3
        if (belt[IN].life > 0 && !belt[IN].robot_on) {
            belt[IN].life--;
            if (belt[IN].life == 0) unavailable_count++;
            belt[IN].robot_on = true;
        }

        // #4
        if (unavailable_count >= K) break;
    }

    cout << stage << "\n";

    return 0;
}