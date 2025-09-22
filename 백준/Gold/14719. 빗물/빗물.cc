#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int h, w;
int result = 0;
vector<int> heights(500);

int main() {
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> heights[i];
    }
    
    for (int i = 1; i < w - 1; i++) {
        int left = 0, right = 0;
        for (int j = 0; j < i; j++) {
            left = max(left, heights[j]);
        }
        for (int j = i + 1; j < w; j++) {
            right = max(right, heights[j]);
        }
        result += max(min(left, right) - heights[i], 0);
    }
    cout << result << "\n";
    return 0;
}