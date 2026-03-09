#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
    새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
    폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
    상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.

    폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.
*/

string original, bomb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> original >> bomb;
    
    string stack = "";
    int bomb_length = bomb.length();
    for (const char& c : original) {
        stack.push_back(c);
        if (stack.length() >= bomb_length) {
            bool included = true;
            for (int i = 0; i < bomb_length; i++) {
                if (stack[stack.length() - 1 - i] != bomb[bomb_length - 1 - i]) {
                    included = false;
                    break;
                }
            }
            if (included) {
                for (int i = 0; i < bomb_length; i++) {
                    stack.pop_back();
                }
            }
        }
    }

    if (stack.empty()) stack = "FRULA";
    cout << stack << "\n";
    
    return 0;
}