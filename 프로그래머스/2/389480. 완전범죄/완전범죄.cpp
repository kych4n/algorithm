#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
    각 상태를 한 번에 기록해야 함
     
*/

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 1e9+7;
    
    vector<vector<bool>> dp(n+1, vector<bool>(m+1));
    int info_size = info.size();
    dp[0][0] = true;
    for (int i=0; i<info_size; i++) {
        vector<vector<bool>> temp_dp(n+1, vector<bool>(m+1));
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                if (dp[j][k]) {
                    if (j + info[i][0] < n) {
                        temp_dp[j + info[i][0]][k] = true;
                    }
                    if (k + info[i][1] < m) {
                        temp_dp[j][k + info[i][1]] = true;
                    }
                }
            }
        }
        dp = temp_dp;
    }
    
    for (int j=0; j<n; j++) {
        for (int k=0; k<m; k++) {
            if (dp[j][k]) {
                answer = min(answer, j);
            }
        }
    }
    if (answer == 1e9+7) answer = -1;
    return answer;
}