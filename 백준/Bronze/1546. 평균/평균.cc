#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double score;
vector<double> scores;

double get_new_mean() {
    double max_value = *max_element(scores.begin(), scores.end());
    double sum = 0;
    for (double score: scores) {
        sum += score;
    }
    return sum / max_value * 100 / n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> score;
        scores.push_back(score);
    }
    cout << get_new_mean() << "\n";
    return 0;
}
