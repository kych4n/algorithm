#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    112345677 -> 원본 수열, 누적 합 수열 모두 비내림차순
    
    1. 누적 합 구하기
    2. 순회하면서, k+누적합[i]가 begin+i에 있는지 lower_bound
        2-1. end면 무시
        2-2. 같지 않으면 무시
        2-3. length보다 작으면 minidx, maxidx 갱신
*/

vector<int> solution(vector<int> sequence, int k) {
    int N = sequence.size();
    
    int min_length = 1e9+7;
    int min_idx = 1e9+7;
    int max_idx = -1;
    
    vector<int> culmative_sums(N);
    culmative_sums[0] = sequence[0];
    for (int i=1; i<N; i++) {
        culmative_sums[i] = culmative_sums[i-1] + sequence[i];
    } 
    
    auto it = lower_bound(culmative_sums.begin(), culmative_sums.end(), k);
    if (it != culmative_sums.end()) {
        int target_idx = it-culmative_sums.begin();
        int value = culmative_sums[target_idx];
        if (k == value && target_idx + 1 < min_length) {
            min_length = target_idx + 1;
            min_idx = 0;
            max_idx = target_idx;
        }
    }
    
    for (int i=0; i<N; i++) {
        int target = k + culmative_sums[i];
        auto it = lower_bound(culmative_sums.begin(), culmative_sums.end(), target);
        if (it == culmative_sums.end()) continue;
        int target_idx = it-culmative_sums.begin();
        int value = culmative_sums[target_idx];
        if (target != value) continue;
        if (target_idx - i < min_length) {
            min_length = target_idx - i;
            min_idx = i+1;
            max_idx = target_idx;
        }
    } 
    
    vector<int> answer {min_idx, max_idx};
    return answer;
}