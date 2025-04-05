#include <iostream>
#include <vector>
using namespace std;

vector<int> scores(1);

int solve(int n) {
    vector<pair<int, int> > maxScores(n + 1);
    maxScores[n] = {scores[n], 0};
    for (int i = n; i > 0; i--) {
        if (i - 2 >= 0) {
            maxScores[i - 2].first = max(maxScores[i - 2].first,
                                         max(maxScores[i].first, maxScores[i].second) + scores[i - 2]);
        }
        if (i - 1 >= 0) {
            maxScores[i - 1].second = max(maxScores[i - 1].second, maxScores[i].first + scores[i - 1]);
        }
    }
    return max(max(maxScores[0].first, maxScores[0].second), max(maxScores[1].first, maxScores[1].second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, score;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> score;
        scores.push_back(score);
    }
    cout << solve(n) << "\n";
    return 0;
}
