#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, blue = 0, white = 0;

vector<vector<int> > paper(128, vector<int>(128));

void divideAndConcuer(int startY, int startX, int length) {
    int color = paper[startY][startX];
    for (int dy = 0; dy < length; dy++) {
        for (int dx = 0; dx < length; dx++) {
            if (color != paper[startY + dy][startX + dx]) {
                int nextLength = length / 2;
                divideAndConcuer(startY, startX, nextLength);
                divideAndConcuer(startY + nextLength, startX, nextLength);
                divideAndConcuer(startY, startX + nextLength, nextLength);
                divideAndConcuer(startY + nextLength, startX + nextLength, nextLength);
                return;
            }
        }
    }
    if (color) {
        blue += 1;
    } else {
        white += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    divideAndConcuer(0, 0, n);
    cout << white << "\n" << blue;
    return 0;
}
