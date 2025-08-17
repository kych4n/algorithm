#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, my_score, score, p, ranking = 1;
vector<int> scores;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> my_score >> p;
	for (int i = 0; i < n; i++) {
		cin >> score;
		scores.push_back(score);
	}
	if (n == p && scores.back() >= my_score) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (scores[i] > my_score) {
			ranking += 1;
		} 
		else {
			break;
		}
	}
	cout << ranking << "\n";
	return 0;
}