#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

/*
    접두사의 길이가 가장 긴 쌍을 출력, 여러 개일 때에는 입력되는 순서대로 제일 앞쪽에 있는 순으로 출력.
    - 비슷함을 찾을 때는 문자열 정렬, 위치, 최대 접두사 길이
*/
int N;

int get_prefix_length(const string& a, const string& b) {
    int prefix_length = 0;
    int min_length = min(a.length(), b.length());
    for (int i = 0; i < min_length; i++) {
        if (a[i] == b[i]) prefix_length++;
        else break;
    }
    return prefix_length;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<string> original(N);
    vector<pair<string, int>> sorted(N);
    for (int i = 0; i < N; i++) {
        cin >> original[i];
        sorted[i] = { original[i], i };
    }

    sort(sorted.begin(), sorted.end());

    int max_prefix_length = 0;
    vector<int> mpl(N);
    for (int i = 0; i < N - 1; i++) {
        int current_prefix_length = get_prefix_length(sorted[i].first, sorted[i + 1].first);
        max_prefix_length = max(max_prefix_length, current_prefix_length);
        mpl[sorted[i].second] = max(mpl[sorted[i].second], current_prefix_length);
        mpl[sorted[i + 1].second] = max(mpl[sorted[i + 1].second], current_prefix_length);
    }

    int first_idx = -1;
    for (int i = 0; i < N; i++) {
        if (mpl[i] == max_prefix_length) {
            cout << original[i] << "\n";
            first_idx = i;
            break;
        }
    }
    for (int i = first_idx + 1; i < N; i++) {
        if (get_prefix_length(original[first_idx], original[i]) == max_prefix_length) {
            cout << original[i] << "\n";
            break;
        }
    }

    return 0;
}