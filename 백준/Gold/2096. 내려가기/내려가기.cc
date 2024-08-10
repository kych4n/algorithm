#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, col;
int dy[] = { -1,0,1 };
vector<int> new_line(3);
vector<pair<int, int>> before_score(3, { 0, 1e9 + 7 });
vector<pair<int, int>> new_score(3, { 0, 1e9 + 7 });

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> new_line[i];
		for (int j = 0; j < 3; j++) {
			before_score[i].first = new_line[i];
			before_score[i].second = new_line[i];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> new_line[j];
			for (int k = 0; k < 3; k++) {
				col = j + dy[k];
				if (col >= 0 && col < 3) {
					new_score[j].first = max(new_score[j].first, before_score[col].first + new_line[j]);
					new_score[j].second = min(new_score[j].second, before_score[col].second + new_line[j]);
				}
			}
		}
		before_score = new_score;
		new_score = vector<pair<int, int>> (3, { 0, 1e9 + 7 });
	}

	int max_result = 0;
	int min_result = 1e9 + 7;
	for (int i = 0; i < 3; i++) {
		max_result = max(max_result, before_score[i].first);
		min_result = min(min_result, before_score[i].second);
	}
	cout << max_result << " " << min_result << "\n";

	return 0;
}