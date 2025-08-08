#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int dh[] = {1,-1,0,0};
int dw[] = {0,0,1,-1};
unordered_map<char, int> direction_to_index = {
    {'S', 0}, {'N', 1}, {'E', 2}, {'W', 3}
};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int max_h = park.size();
    int max_w = park[0].size();
    pair<int, int> current;
    for (int i=0; i<max_h; i++) {
        for (int j=0; j<max_w; j++) {
            if (park[i][j] == 'S') {
                current = {i, j};
                break;
            }
        }
    }
    for (string route: routes) {
        bool isPossible = true;
        char direction = route[0];
        int direction_index = direction_to_index[direction];
        int max_amount = route[2] - '0';
        for (int amount=1; amount <= max_amount; amount++) {
            int next_h = current.first + dh[direction_index] * amount;
            int next_w = current.second + dw[direction_index] * amount;
            if (!(next_h >= 0 && next_h < max_h && next_w >= 0 && next_w < max_w)) {
                isPossible = false;
                break;
            }
            if (park[next_h][next_w] == 'X') {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            current.first += dh[direction_index] * max_amount;
            current.second += dw[direction_index] * max_amount;
        }
    }
    answer.push_back(current.first);
    answer.push_back(current.second);
    return answer;
}