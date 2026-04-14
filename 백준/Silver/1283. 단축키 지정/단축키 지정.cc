#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

/*
    [입력] 문자열
    [출력] 단축키 지정된 문자열

    - 어떤 알파벳이 이미 지정되어 있는가
    - 그 문자열에서는 몇 번째가 단축키인가
*/

int N;
vector<bool> visited(26);
string str;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, str);

        int M = str.length();
        bool is_done = false;
        int where = 1e9 + 7;

        // #1
        bool word_first = true;
        for (int j = 0; j < M; j++) {
            if (str[j] == ' ') {
                word_first = true;
                continue;
            }

            int idx;
            if (isupper(str[j])) idx = str[j] - 'A';
            else idx = str[j] - 'a';

            if (word_first && !visited[idx]) {
                visited[idx] = true;
                where = j;
                is_done = true;
                break;
            }

            word_first = false;
        }

        // #2
        if (!is_done) {
            for (int j = 0; j < M; j++) {
                if (str[j] == ' ') {
                    continue;
                }

                int idx = tolower(str[j]) - 'a';
                if (!visited[idx]) {
                    visited[idx] = true;
                    where = j;
                    break;
                }
            }
        }
        
        for (int j = 0; j < M; j++) {
            if (where == j) {
                cout << '[';
            }
            cout << str[j];
            if (where == j) {
                cout << ']';
            }
        }
        cout << "\n";
    }

    return 0;
}