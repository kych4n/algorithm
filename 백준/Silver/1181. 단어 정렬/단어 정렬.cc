#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
string s;
vector<string> words;
bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		words.push_back(s);
	}
	sort(words.begin(), words.end(), compare);
	words.erase(unique(words.begin(), words.end()), words.end());
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << "\n";
	}
	return 0;
}