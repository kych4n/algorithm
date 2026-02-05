#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int T, K;
string W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		vector<vector<int>> alphabet_loc(26);

		cin >> W >> K;
		int length = W.length();
		
		for (int i = 0; i < length; i++) {
			alphabet_loc[W[i]-'a'].push_back(i);
		}

		int three_length = 1e9 + 7;
		int four_length = 0;

		for (int i = 0; i < 26; i++) {
			int count = alphabet_loc[i].size();
			if (count < K) continue;
			for (int j = 0; j < count - K + 1; j++) {
				three_length = min(three_length, alphabet_loc[i][j + K - 1] - alphabet_loc[i][j] + 1);
				four_length = max(four_length, alphabet_loc[i][j + K - 1] - alphabet_loc[i][j] + 1);
			}
		}
		if (three_length == 1e9 + 7 && four_length == 0) {
			cout << -1 << "\n";
			continue;
		}
		cout << three_length << " " << four_length << "\n";
	}

	return 0;
}