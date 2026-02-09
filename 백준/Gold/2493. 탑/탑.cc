#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<pair<int, int>> building;
    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        while (!building.empty() && building.back().first < h) {
            building.pop_back();
        }
        if (building.empty()) {
            cout << 0 << " ";
        }
        else {
            cout << building.back().second << " ";
        }
        building.push_back({ h, i });
    }

    return 0;
}