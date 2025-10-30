#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int N;
long long M;
long long result = 0;
vector<long long> A;
vector<long long> nj;

void init() {
    cin >> N >> M;
    A.resize(N + 1);
    nj.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        nj[i] = nj[i - 1] + A[i];
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int left = 0, right = 1; 
    while (left <= N && right <= N) {
        long long subarray_sum = nj[right] - nj[left];
        if (subarray_sum == M) {
            result += 1;
            left++;
        }
        else if (subarray_sum > M) {
            left++;
        }
        else {
            right++;
        }
    }

    cout << result << "\n";

    return 0;
}