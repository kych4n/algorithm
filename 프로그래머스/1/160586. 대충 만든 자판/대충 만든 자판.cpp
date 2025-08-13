#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> key_to_count;
    for (char alphabet = 'A'; alphabet <= 'Z'; alphabet++) {
        key_to_count[alphabet] = 1e9 + 7;
    }
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            key_to_count[keymap[i][j]] = min(key_to_count[keymap[i][j]], j + 1);
        }
    }
    for (int i = 0; i < targets.size(); i++) {
        int temp_result = 0;
        for (int j = 0; j < targets[i].size(); j++) {
            if (key_to_count[targets[i][j]] == 1e9 + 7) {
                temp_result = -1;
                break;
            }
            temp_result += key_to_count[targets[i][j]];
        }
        answer.push_back(temp_result);
    }
    return answer;
}