#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Result {
    int min_number = 1e9 + 7;
    int visible_count;
};
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    /*
        - 어떤 건물이 볼 수 있는 건물의 개수, 가장 가까운 건물의 번호 중 작은 것
        - O(10**5) -> O(N)
        - 왼쪽, 오른쪽 나눠서 생각
        - 어떤 방향으로 높이가 L인 건물이 있다면, 그 뒤에 있는 건물은 영향이 없음
        - 자신과 가까운 것에 큰 영향을 받음 -> 스택

        - 현재 높이보다 작은 top들을 모두 pop -> 남은 개수 = 볼 수 있는 건물의 개수
    */
    cin >> N;
    vector<int> height(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    vector<Result> result(N + 1);

    // 왼쪽
    stack<pair<int, int>> left;
    for (int i = 1; i <= N; i++) {
        while (!left.empty() && left.top().first <= height[i]) left.pop();
        result[i].visible_count += left.size();
        if (!left.empty()) result[i].min_number = left.top().second;
        left.push({ height[i], i });
    }

    // 오른쪽
    stack<pair<int, int>> right;
    for (int i = N; i >= 1; i--) {
        while (!right.empty() && right.top().first <= height[i]) right.pop();
        result[i].visible_count += right.size();
        if (!right.empty()) {
            if (abs(result[i].min_number - i) > abs(i - right.top().second)) {
                result[i].min_number = right.top().second;
            }
        }
        right.push({ height[i], i });
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i].visible_count;
        if (result[i].visible_count > 0) {
            cout << " " << result[i].min_number << "\n";
        }
        else {
            cout << "\n";
        }
    }

    return 0;
}