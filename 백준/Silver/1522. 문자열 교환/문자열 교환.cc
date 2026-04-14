#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    [입력] a와 b로만 이루어진 문자열
    [출력] a를 모두 연속으로 만들기 위해서 필요한 교환의 최소 횟수

    N = 1000
    O(N*N)

    - a를 연속으로 만드는 것 = b를 연속으로 만드는 것

*/

string str;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    
    int N = str.length();
    int a_count = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == 'a') {
            a_count++;
        }
    }

    int result = 1e9 + 7;
    
    for (int i = 0; i < N; i++) {
        int temp_result = 0;
        for (int j = 0; j < a_count; j++) {
            if (str[(i + j) % N] == 'b') temp_result++;
        }
        result = min(result, temp_result);
    }

    cout << result << "\n";

    return 0;
}