#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    서로 다른 K개의 초밥을 먹으면 쿠폰에 적힌 번호의 초밥을 줌
    먹을 수 있는 초밥 가짓수의 최댓값을 구해야 하는데, K개의 초밥과 쿠폰에 적힌 번호의 초밥이 안겹치면 좋음
    종류 당 개수를 기억하는 것이 필요, 종류의 수를 추적 - 종류 당 개수가 0이 되면 -1, 1 이상이 되면 +1
*/

int N, d, k, c;
int result = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> d >> k >> c;
    vector<int> sushi(N);
    vector<int> count(d + 1);
    int cur_d = 0;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }
    for (int i = 0; i < N + k; i++) {
        if (i >= k) {
            count[sushi[(i - k) % N]]--;
            if (count[sushi[(i - k) % N]] == 0) {
                cur_d--;
            }
        }
        count[sushi[i % N]]++;
        if (count[sushi[i % N]] == 1) {
            cur_d++;
        }
        
        int temp_result = cur_d;
        if (i >= k - 1 && count[c] == 0) {
            temp_result += 1;
        }
        result = max(result, temp_result);
    }
   
    cout << result << "\n";

    return 0;
}