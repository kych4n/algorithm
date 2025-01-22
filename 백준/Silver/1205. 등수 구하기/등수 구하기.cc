#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int p, n, score, new_score;
vector<int> scores;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> new_score >> p;
	for (int i = 0; i < n; i++) {
		cin >> score;
		scores.push_back(score);
	}

	if (n == 0) {
		cout << 1 << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (new_score >= scores[i] && new_score != scores.back()) {
			cout << i + 1 << "\n";
			return 0;
		}
	}

	if (n == p) {
		cout << -1 << "\n";
	}
	else {
		if (new_score == scores.back()) {
			for (int i = 0; i < n; i++) {
				if (new_score == scores[i]) {
					cout << i + 1 << "\n";
					return 0;
				}
			}
		}
		else {
			cout << n + 1 << "\n";
		}
	}

	return 0;
}
