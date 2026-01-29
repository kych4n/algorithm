#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int N;
set<string> word;
vector<pair<string, int>> word_loc;
int max_prefix_count = 0;
set<pair<string, int>> s;

int get_prefix_count(string a, string b) {
	int a_length = a.length();
	int b_length = b.length();
	int common_length = min(a_length, b_length);
	int count = 0;
	for (int i = 0; i < common_length; i++) {
		if (a[i] == b[i]) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (word.find(str) != word.end()) continue;
		word.insert(str);
		word_loc.push_back({ str, i });
	}
	
	sort(word_loc.begin(), word_loc.end());

	for (int i = 0; i < N - 1; i++) {
		int prefix_count = get_prefix_count(word_loc[i].first, word_loc[i + 1].first);
		if (max_prefix_count < prefix_count) {
			max_prefix_count = prefix_count;
			s.clear();
			s.insert(word_loc[i]);
			s.insert(word_loc[i + 1]);
		}
		else if (max_prefix_count == prefix_count) {
			s.insert(word_loc[i]);
			s.insert(word_loc[i + 1]);
		}
	}

	vector<pair<int, string>> v;
	for (auto p : s) {
		v.push_back({ p.second, p.first });
	}
	sort(v.begin(), v.end());
	cout << v[0].second << "\n";

	for (int i = 1; i < v.size(); i++) {
		if (v[0].second.substr(0, max_prefix_count) == v[i].second.substr(0, max_prefix_count)) {
			cout << v[i].second << "\n";
			break;
		}
	}

	return 0;
}