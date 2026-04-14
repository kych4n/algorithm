#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    [입력] A의 위치, B의 위치
    [출력] A가 B에 도달하는 데 걸리는 시간

    - X+1, X-1, 2X
    - 시간 증가시키면서 위치 변화시키기
*/

int N, K;
const int MAX = 100000;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    if (N > K) {
        cout << N - K << "\n";
        return 0;
    }

    vector<int> min_cost(MAX + 1, 1e9 + 7);

    int cur_time = 0;
    queue<int > q;
    q.push(N);
    min_cost[N] = 0;

    while (true) {
        cur_time++;

        int cur_size = q.size();
        for (int i = 0; i < cur_size; i++) {
            int cur_loc = q.front();
            q.pop();

            if (cur_loc + 1 <= MAX && min_cost[cur_loc + 1] > cur_time) {
                min_cost[cur_loc + 1] = cur_time;
                q.push(cur_loc + 1);
            }
            if (cur_loc - 1 >= 0 && min_cost[cur_loc - 1] > cur_time) {
                min_cost[cur_loc - 1] = cur_time;
                q.push(cur_loc - 1);
            }
            if (cur_loc * 2 <= MAX && min_cost[cur_loc * 2] > cur_time) {
                min_cost[cur_loc * 2] = cur_time;
                q.push(cur_loc * 2);
            }

            if (min_cost[K] != 1e9 + 7) {
                cout << min_cost[K] << "\n";
                return 0;
            }
        }
    }

    return 0;
}