#include <iostream>
#include <vector>
using namespace std;

int n;
string str;
int result = 1e9 + 7;
vector<pair<char, int>> info;

void start_front(char target) {
	bool flag = false;
	int temp_result = 0;
	for (pair<char, int> x : info) {
		if (x.first != target) {
			flag = true;
		}
		if (flag && x.first == target) {
			temp_result += x.second;
		}
	}
	result = min(result, temp_result);
}

void start_back(char target) {
	bool flag = false;
	int temp_result = 0;
	for (int i = info.size() - 1; i >= 0; i--) {
		if (info[i].first != target) {
			flag = true;
		}
		if (flag && info[i].first == target) {
			temp_result += info[i].second;
		}
	}
	result = min(result, temp_result);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> str;
	char current_char = str[0];
	int current_count = 1;
	for (int i = 1; i < n; i++) {
		if (current_char == str[i]) {
			current_count += 1;
		}
		else {
			info.push_back({ current_char, current_count });
			current_char = str[i];
			current_count = 1;
		}
	}
	info.push_back({ current_char, current_count });

	start_front('R');
	start_front('B');
	start_back('R');
	start_back('B');

	cout << result << "\n";
	return 0;
}