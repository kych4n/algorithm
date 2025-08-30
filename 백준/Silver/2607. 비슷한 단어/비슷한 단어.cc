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
		if (abs((int)(words[0].length() - words[i].length())) > 1) {
			continue;
		}
		vector<int> alphabetCount = targetAlphabetCount;
		for (int j = 0; j < words[i].length(); j++) {
			alphabetCount[words[i][j] - 'A'] -= 1;
		}
		int differenceCount = 0;
		for (int j = 0; j < 26; j++) {
			differenceCount += abs(alphabetCount[j]);
		}
		if (differenceCount <= 2) {
			result += 1;
		}
		
	}
	cout << result << "\n";

	return 0;
}