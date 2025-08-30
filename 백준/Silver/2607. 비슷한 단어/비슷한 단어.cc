#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, result = 0;
string word;
vector<string> words;
vector<int> targetAlphabetCount(26);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		words.push_back(word);
	}
	for (int i = 0; i < words[0].length(); i++) {
		targetAlphabetCount[words[0][i] - 'A'] += 1;
	}
	for (int i = 1; i < n; i++) {
		vector<int> alphabetCount(26);
		for (int j = 0; j < words[i].length(); j++) {
			alphabetCount[words[i][j] - 'A'] += 1;
		}
		vector<int> problems;
		for (int j = 0; j < 26; j++) {
			if (alphabetCount[j] != targetAlphabetCount[j]) {
				problems.push_back(alphabetCount[j] - targetAlphabetCount[j]);
			}
		}
		if (problems.empty()) {
			result += 1;
		}
		else if (problems.size() == 1 && abs(problems[0]) == 1) {
			result += 1;
		}
		else if (problems.size() == 2 && abs(problems[0]) == 1 && abs(problems[1]) == 1) {
			if (problems[0] + problems[1] == 0) {
				result += 1;
			}
		}
	}
	cout << result << "\n";

	return 0;
}