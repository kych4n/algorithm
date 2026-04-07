#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    [입력] S, E
    [출력] S부터 E까지가 팰린드롬인가

    - 어느 S, E를 물어도 답이 나와야 함 -> 저장 -> DP
    - 길이가 큰 팰린드롬은 길이가 작은 팰린드롬의 영향을 받음
*/

int N, M, S, E;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<vector<bool>> palindrome(N + 1, vector<bool>(N + 1));

    for (int i = 1; i <= N; i++) {
        palindrome[i][i] = true;
    }

    for (int start = 1; start <= N; start++) {
        int end = start + 1;
        if (end > N) break;
        palindrome[start][end] = (v[start] == v[end]);
    }

    for (int length = 3; length <= N; length++) {
        for (int start = 1; start <= N; start++) {
            int end = start + length - 1;
            if (end > N) break;
            palindrome[start][end] = (v[start] == v[end]) && palindrome[start + 1][end - 1];
        }
    }

    cin >> M;
    while (M--) {
        cin >> S >> E;
        cout << (palindrome[S][E] ? 1 : 0) << "\n";
    }
    
    return 0;
}