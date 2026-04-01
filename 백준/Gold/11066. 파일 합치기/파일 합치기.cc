#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

/*
    두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 
    이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 되도록 파일을 합쳐나가고, 
    최종적으로는 하나의 파일로 합친다. 
    두 개의 파일을 합칠 때 필요한 비용이 두 파일 크기의 합이라고 가정할 때, 
    최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.

    연속이 되도록 합친다는 조건 때문에 우선순위 큐는 못씀
    합칠 때, 이전에 합친 것이 쓰임 -> DP
    크기가 작은 길이부터
    현재 조합은 다 찾았음
*/

int T, K, number;
const int INF = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> K;
        vector<int> v(K + 1);
        vector<int> culmative_sum(K + 1);
        vector<vector<int>> dp(K + 1, vector<int>(K + 1, INF));
        for (int i = 1; i <= K; i++) {
            cin >> v[i];
            culmative_sum[i] = culmative_sum[i - 1] + v[i];
            dp[i][i] = 0;
        }
        
        for (int length = 2; length <= K; length++) {
            for (int i = 1; i <= K; i++) {
                int j = i + length - 1;
                if (j > K) break;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + culmative_sum[j] - culmative_sum[i - 1];
                    if (dp[i][j] > cost) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        cout << dp[1][K] << "\n";
    }
    
    return 0;
}