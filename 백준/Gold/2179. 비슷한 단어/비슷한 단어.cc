#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int N;
string word;
map<string, set<string>> head_to_word;
map<string, int> head_to_min_loc;
map<string, int> word_to_loc;
string max_head = "";
int min_loc = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		word_to_loc[word] = i;
		int length = word.length();
		for (int j = 1; j <= length; j++) {
			string head = word.substr(0, j);
			head_to_word[head].insert(word);
			if (head_to_min_loc.find(head) == head_to_min_loc.end()) {
				head_to_min_loc[head] = 1e9 + 7;
			}
			head_to_min_loc[head] = min(head_to_min_loc[head], i);
		}
	}
	
	for (const pair <string, set<string>> &p : head_to_word) {
		string head = p.first;
		if (p.second.size() <= 1) {
			continue;
		}
		if (max_head.length() < head.length()) {
			max_head = head;
			min_loc = head_to_min_loc[head];
		}
		else if (max_head.length() == head.length() && min_loc > head_to_min_loc[head]) {
			max_head = head;
			min_loc = head_to_min_loc[head];
		}
	}
	
	vector<pair<string, int>> v;
	for (string s : head_to_word[max_head]) {
		v.push_back({ s, word_to_loc[s] });
	}
	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second < b.second;
	});
	cout << v[0].first << "\n" << v[1].first << "\n";

	return 0;
}