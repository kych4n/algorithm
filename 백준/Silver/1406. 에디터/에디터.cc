#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string str;
int N, M;
stack<char> leftstack, rightstack;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    N = str.length();
    for (int i = 0; i < N; i++) {
        leftstack.push(str[i]);
    }

    cin >> M;
    for (int t = 0; t < M; t++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (!leftstack.empty()) {
                rightstack.push(leftstack.top());
                leftstack.pop();
            }
        }
        else if (cmd == 'D') {
            if (!rightstack.empty()) {
                leftstack.push(rightstack.top());
                rightstack.pop();
            }
        }
        else if (cmd == 'B') {
            if (!leftstack.empty()) {
                leftstack.pop();
            }
        }
        else if (cmd == 'P') {
            char c;
            cin >> c;
            leftstack.push(c);
        }
    }

    while (!leftstack.empty()) {
        rightstack.push(leftstack.top());
        leftstack.pop();
    }

    while (!rightstack.empty()) {
        cout << rightstack.top();
        rightstack.pop();
    }

    return 0;
}