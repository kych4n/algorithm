#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[1000000];
int B, C;
long long result = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        A[i] -= B;
        result++;
        if (A[i] > 0) {
            result += A[i] / C;
            if (A[i] % C > 0) result++;
        }
    }

    cout << result << "\n";

    return 0;
}