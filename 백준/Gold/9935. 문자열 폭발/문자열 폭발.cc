#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    int a_length = a.length();
    int b_length = b.length();
    string result = "";

    for (int i = 0; i < a_length; i++) {
        result.push_back(a[i]);
        if (result.length() >= b_length) {
            bool is_match = true;
            for (int j = 0; j < b_length; j++) {
                if (result[result.length() - 1 - j] != b[b_length - 1 - j]) {
                    is_match = false;
                    break;
                }
            }

            if (is_match) {
                for (int j = 0; j < b_length; j++) {
                    result.pop_back();
                }
            }
        }
    }

    if (result.empty()) {
        cout << "FRULA\n";
    }
    else {
        cout << result << "\n";
    }
    
    return 0;
}