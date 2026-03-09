#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

/*
    블루레이에는 총 N개의 강의가 들어가는데, 블루레이를 녹화할 때, 즉, i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.

    블루레이의 개수를 가급적 줄이려고 한다. 이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 단, M개의 블루레이는 모두 같은 크기이어야 한다.

    가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.

    - N = 100000 -> O(NlogN)
    - 블루레이 최소 크기를 찾아야 함 -> 매개변수 탐색
    - left = 1, right = 전체 합
    - target 정하고, 만든 블루레이의 개수가 M보다 작으면(target이 큼) -> target을 줄임
                          블루레이의 개수가 M보다 크면(target이 작음) -> target을 늘림
                          블루레이의 개수가 M과 같으면, 최솟값을 구해야 하기 때문에 -> target을 줄임
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    vector<int> lec(N);

    int left = 0, right = 0;
    for (int i = 0; i < N; i++) {
        cin >> lec[i];
        left = max(left, lec[i]);
        right += lec[i];
    }

    int result = INT32_MAX;
    while (left <= right) {
        int target = (left + right) / 2;
        int blulay_count = 1;
        int cur_size = 0;
        for (const int& l : lec) {
            if (cur_size + l <= target) {
                cur_size += l;
            }
            else {
                blulay_count++;
                cur_size = l;
            }
        }
        if (blulay_count <= M) {
            result = min(result, target);
            right = target - 1;
        }
        else {
            left = target + 1;
        }
    }

    cout << result << "\n";
    return 0;
}