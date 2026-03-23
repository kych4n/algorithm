#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    집에 공유기 C개를 설치하려고 한다. 
    가장 인접한 두 공유기 사이의 거리의 최대

    두 공유기 사이의 거리를 이분탐색하면서 
*/

int N, C;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    int left = 1, right = x.back() - x.front(), mid;
    int install_count, last_install_point, result = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        install_count = 1, last_install_point = x.front();
        for (int i = 1; i < N; i++) {
            if (last_install_point + mid <= x[i]) {
                last_install_point = x[i];
                install_count++;
            }
        }
        if (install_count >= C) {
            result = max(result, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << result << "\n";

    return 0;
}