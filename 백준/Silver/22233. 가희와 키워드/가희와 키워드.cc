#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int n, m;
string keyword, content;
unordered_set<string> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> keyword;
		s.insert(keyword);
	}
	for (int i = 0; i < m; i++) {
		cin >> content;
		vector<int> commaIdx;
		commaIdx.push_back(-1);
		for (int j = 0; j < content.length(); j++) {
			if (content[j] == ',') {
				commaIdx.push_back(j);
			}
		}
		commaIdx.push_back(content.length());
		for (int j = 0; j < commaIdx.size() - 1; j++) {
			string target = content.substr(commaIdx[j] + 1, commaIdx[j + 1] - commaIdx[j] - 1);
			s.erase(target);
		}
		cout << s.size() << "\n";
	}
	return 0;
}