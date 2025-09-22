#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int h, w;
int left_idx, right_idx;
int result = 0;
vector<int> heights(500);

int main() {
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> heights[i];
    }
    
    left_idx = 0;
    right_idx = 0;
    while (true) {
        int right_height = 0;
        for (int i = left_idx + 1; i < w; i++) {
            if (right_height <= heights[i]) {
                right_height = heights[i];
                right_idx = i;
            }
            if (right_height >= heights[left_idx]) {
                break;
            }
        }
        if (left_idx == right_idx) {
            right_idx = w - 1;
        }
        int criteria_height = min(heights[left_idx], heights[right_idx]);
        for (int i = left_idx + 1; i < right_idx; i++) {
            result += criteria_height - heights[i];
        }
        left_idx = right_idx;
        if (left_idx == w - 1) {
            break;
        }
    }
    cout << result << "\n";
    return 0;
}