#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int p, l, m;
string n;
vector<vector<pair<string, int>>> rooms;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p >> m;
	for (int i = 0; i < p; i++) {
		cin >> l >> n;
		if (rooms.empty()) {
			vector<pair<string, int>> room;
			room.push_back({ n, l });
			rooms.push_back(room);
		}
		else {
			for (int j = 0; j < rooms.size() + 1; j++) {
				if (j == rooms.size()) {
					vector<pair<string, int>> room;
					room.push_back({ n, l });
					rooms.push_back(room);
					break;
				}
				int makerLevel = rooms[j][0].second;
				int participantCount = rooms[j].size();
				if (l >= makerLevel - 10 && l <= makerLevel + 10 && participantCount < m) {
					rooms[j].push_back({ n, l });
					break;
				}
			}
		}
	}

	for (int i = 0; i < rooms.size(); i++) {
		sort(rooms[i].begin(), rooms[i].end());
		if (rooms[i].size() == m) {
			cout << "Started!\n";
		}
		else {
			cout << "Waiting!\n";
		}
		for (pair<string, int> info : rooms[i]) {
			cout << info.second << " " << info.first << "\n";
		}
	}

	return 0;
}