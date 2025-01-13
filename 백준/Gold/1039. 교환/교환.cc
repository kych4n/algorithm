#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int MAX = 1e9 + 7;

void swap(string& cur_string, int i, int j) {
	char temp = cur_string[i];
	cur_string[i] = cur_string[j];
	cur_string[j] = temp;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string n;
	int k, length;
	cin >> n >> k;
	length = n.length();
	if (length == 1 || (length == 2 && n[1] == '0')) {
		cout << -1 << '\n';
		exit(0);
	}

	queue<string> q;
	q.push(n);

	int cur_count = 0;
	int max_value = 0;

	while (!q.empty() && cur_count < k) {
		int cur_size = q.size();
		set<string> visited;

		for (int x = 0; x < cur_size; x++) {
			string cur_string = q.front();
			q.pop();
			for (int i = 0; i < length - 1; i++) {
				for (int j = i + 1; j < length; j++) {
					if (i == 0 && cur_string[j] == '0') {
						continue;
					}
					swap(cur_string, i, j);
					if (visited.find(cur_string) == visited.end()) {
						if (cur_count == k - 1 && max_value < stoi(cur_string)) {
							max_value = stoi(cur_string);
						}
						q.push(cur_string);
						visited.insert(cur_string);
					}
					swap(cur_string, i, j);
				}
			}
		}
		cur_count += 1;
	}

	if (cur_count != k) {
		cout << -1 << '\n';
	}
	else {
		cout << max_value << '\n';
	}

	return 0;
}