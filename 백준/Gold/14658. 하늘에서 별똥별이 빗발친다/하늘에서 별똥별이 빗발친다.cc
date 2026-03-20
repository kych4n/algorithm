#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    최대한 많은 별똥별을 튕겨내도록 트램펄린을 배치했을 때, 지구에는 몇 개의 별똥별이 부딪히게 될까? 
    별똥별이 떨어지는 위치는 겹치지 않으며 별똥별은 트램펄린의 모서리에 부딪혀도 튕겨나간다!
    트램펄린은 비스듬하게 배치 할 수 없다.

    - 별똥별의 위치가 좌표로 주어짐
    - N*M = 10**10이므로 전체를 탐색하는 건 무리
    - 별똥별 하나를 잡고 이를 모서리에 두는 방식은 중간에 포함되는 경우를 고려하지 못함
    - 별똥별 두 개를 포함하는 최적화된 영역의 시작점은 그 두 개를 잡고 최소최소
*/

struct Star {
    int r, c;
};
int N, M, L, K, result = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> L >> K;
    vector<Star> stars(K);
    for (int i = 0; i < K; i++) {
        cin >> stars[i].r >> stars[i].c;
    }
    
    for (int i = 0; i < K; i++) {
        for (int j = i; j < K; j++) {
            int start_r = min(stars[i].r, stars[j].r);
            int start_c = min(stars[i].c, stars[j].c);
            int end_r = start_r + L;
            int end_c = start_c + L;
            int included_count = 0;
            for (int g = 0; g < K; g++) {
                if (stars[g].r >= start_r && stars[g].r <= end_r && stars[g].c >= start_c && stars[g].c <= end_c) included_count++;
            }
            result = min(result, K - included_count);
        }
    }

    cout << result << "\n";

    return 0;
}