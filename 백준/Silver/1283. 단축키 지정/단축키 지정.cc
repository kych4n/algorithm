#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n;
string str;
vector<bool> already(26);
vector<int> assigned(30, -1);
vector<string> save_str;

vector<string> split(string str, char delimeter) {
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, delimeter)) {
		for (int i = 0; i < buffer.length(); i++) {
			buffer[i] = tolower(buffer[i]);
		}
		result.push_back(buffer);
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		save_str.push_back(str);

		bool isAssigned = false;

		// 단어의 첫번째 단축키 지정 확인
		int idx = 0;
		vector<string> firsts = split(str, ' ');
		for (int j = 0; j < firsts.size(); j++) {
			char first_word = firsts[j][0];
			if (!already[first_word - 'a']) {
				already[first_word - 'a'] = true;
				assigned[i] = idx;
				isAssigned = true;
				break;
			}
			idx += firsts[j].length();
			idx += 1;
		}

		if (isAssigned) continue;

		// 전체 확인
		for (int j = 0; j < str.length(); j++) {
			if (isalpha(str[j]) && !already[tolower(str[j]) - 'a']) {
				already[tolower(str[j]) - 'a'] = true;
				assigned[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < save_str[i].length(); j++) {
			if (assigned[i] == j) {
				cout << "[" << save_str[i][j] << "]";
			}
			else {
				cout << save_str[i][j];
			}
		}
		cout << "\n";
	}
	return 0;
}