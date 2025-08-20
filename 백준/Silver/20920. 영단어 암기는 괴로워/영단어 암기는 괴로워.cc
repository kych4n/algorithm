#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class WordInfo {
public:
	int frequency;
	int length;
	string word;
	WordInfo(int frequency, int length, string word) {
		this->frequency = frequency;
		this->length = length;
		this->word = word;
	}
};

struct Compare {
	bool operator()(WordInfo& a, WordInfo& b) {
		if (a.frequency == b.frequency) {
			if (a.length == b.length) {
				return a.word > b.word;
			}
			else {
				return a.length < b.length;
			}
		}
		else {
			return a.frequency < b.frequency;
		}
	}
};

int n, m;
string word;
vector<string> words;
unordered_map<string, int> word_to_frequency;
priority_queue<WordInfo, vector<WordInfo>, Compare> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (word.size() >= m) {
			word_to_frequency[word] += 1;
		}
	}
	for (pair<string, int> value : word_to_frequency) {
		pq.push(WordInfo(value.second, value.first.length(), value.first));
	}
	while (!pq.empty()) {
		cout << pq.top().word << "\n";
		pq.pop();
	}
	return 0;
}