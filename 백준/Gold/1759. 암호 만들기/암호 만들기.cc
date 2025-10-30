#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alphabets;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void bt(string& current_str) {
    if (current_str.length() == L) {
        int vowel_count = 0;
        for (char c : current_str) {
            if (is_vowel(c)) {
                vowel_count += 1;
            }
        }
        int not_vowel_count = current_str.length() - vowel_count;
        if (vowel_count >= 1 && not_vowel_count >= 2) {
            cout << current_str << "\n";
        }
        return;
    }
    for (char c : alphabets) {
        if (current_str.back() < c) {
            current_str.push_back(c);
            bt(current_str);
            current_str.pop_back();
        }
    }
}

void init() {
    cin >> L >> C;
    alphabets.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> alphabets[i];
    }
    sort(alphabets.begin(), alphabets.end());
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    for (int i = 0; i <= C - L; i++) {
        string str = "";
        str += alphabets[i];
        bt(str);
    }

    return 0;
}