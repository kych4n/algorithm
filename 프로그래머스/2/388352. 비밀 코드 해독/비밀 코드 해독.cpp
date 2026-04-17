#include <string>
#include <vector>

using namespace std;

/*
    조합의 경우의 수를 다 찾는 것이 불가능할 것이라고 생각했음
    -> 아 직접 계산해볼걸, 30의 5승 해도 2430만이네
    
    조합 구성 ㄱㄱ
    상태를 저장하는 데에는 비트마스킹! 재귀 사용 ㄱㄱ
    
    현재 개수, 현재 조합, 가장 큰 수
    현재 개수가 5이면 확인
    
*/

int get_set_bits(int mask) {
    return __builtin_popcount(mask);
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int m = q.size();
    int answer = 0;
    
    vector<int> q_mask(m);
    for (int i=0; i<m; i++) {
        for (int j=0; j<5; j++) {
            q_mask[i] |= (1 << q[i][j]);
        }
    }
    
    auto dfs = [&](auto self, int count, int comb, int biggest) -> void {
        if (count == 5) {
            for (int i=0; i<m; i++) {
                if (get_set_bits(comb & q_mask[i]) != ans[i]) {
                    return;
                }
            }
            answer++;
            return;
        }
        
        for (int next=biggest + 1; next <= n; next++) {
            self(self, count + 1, comb | (1 << next), next);
        }
    };
    
    dfs(dfs, 0, 0, 0);
    
    return answer;
}