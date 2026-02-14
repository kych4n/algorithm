#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int T, N;
vector<vector<string>> result(10);

bool is_zero(string cur_str) {
    int length = cur_str.length();
    int val = 0;
    int last_sign = 1;
    int last_number = 0;
    for (int i = 0; i < length; i += 2) {
        int cur_number = cur_str[i] - '0';
        if (i == 0) {
            last_number = cur_number;
            continue;
        }
        char sign = cur_str[i - 1];
        if (sign == '+' || sign == '-') {
            val += last_sign * last_number;
            last_number = cur_number;
            last_sign = (sign == '+' ? 1 : -1);
        }
        else if (sign == ' ') {
            last_number *= 10;
            last_number += cur_number;
        }
        if (i == length - 1) {
            val += last_sign * last_number;
            continue;
        }
    }

    if (val == 0) return true;
    return false;
}

void dfs(int cur_number, string cur_str) {
    if (cur_number == 10) {
        return;
    }
    if (cur_number >= 3 && is_zero(cur_str)) {
        result[cur_number].push_back(cur_str);
    }
    dfs(cur_number + 1, cur_str + "+" + to_string(cur_number + 1));
    dfs(cur_number + 1, cur_str + "-" + to_string(cur_number + 1));
    dfs(cur_number + 1, cur_str + " " + to_string(cur_number + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    dfs(1, "1");

    for (int i = 3; i <= 9; i++) {
        sort(result[i].begin(), result[i].end());
    }

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        for (const string& str : result[N]) {
            cout << str << "\n";
        }

        cout << "\n";
    }

    return 0;
}