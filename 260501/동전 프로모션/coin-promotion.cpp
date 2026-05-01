#include <iostream>
#include <vector>
using namespace std;

/*
    최소한의 동전만 사용하여 거슬러주기
    동전의 조합을 찾는 문제 -> DP

*/

const int NOT_UPDATED = 1e9+7;
int N, M;

int main() {
    // Please write your code here.
    cin >> N >> M;

    vector<int> dp(M+1, NOT_UPDATED);
    dp[0] = 0;

    vector<int> A;
    vector<int> B;

    for (int i=0; i<N; i++) {
        char type; int value;
        cin >> type >> value;

        if (type == 'A') A.push_back(value);
        else B.push_back(value);
    }

    for (int value : A) {
        for (int j=0; j<=M-value; j++) {
            if (dp[j] != NOT_UPDATED) {
                dp[j+value] = min(dp[j+value], dp[j]+1);      
            }
        }
    }

    for (int value : B) {
        for (int j=M-value; j>=0; j--) {
            if (dp[j] != NOT_UPDATED) {
                dp[j+value] = min(dp[j+value], dp[j]+1);      
            }
        }
    }

    if (dp[M] == NOT_UPDATED) cout << -1 << "\n";
    else cout << dp[M] << "\n";
    
    return 0;
}