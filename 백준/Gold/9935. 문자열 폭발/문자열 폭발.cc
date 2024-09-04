#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string original, boom;
stack<pair<char, int>> s;
vector<int> save(1000000, -1);
int cur_idx = 0, temp_idx;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> original >> boom;
	int original_length = original.length();
	int boom_length = boom.length();
	for (int i = 0; i < original_length; i++) {
		s.push({ original[i], i });
		if (s.top().first == boom[cur_idx]) {
			save[i] = cur_idx;
			cur_idx += 1;
			if (cur_idx == boom_length) {
				for (int j = 0; j < boom_length; j++) {
					s.pop();
				}
				if (s.empty()) {
					cur_idx = 0;
				}
				else {
					cur_idx = min(save[s.top().second] + 1, boom_length - 1);
				}
				
			}
		}
		else {
			cur_idx = 0;
			if (s.top().first == boom[cur_idx]) {
				save[i] = cur_idx;
				cur_idx += 1;
			}
		}
	}

	string result = "";

	if (s.empty()) {
		cout << "FRULA" << "\n";
		return 0;
	}

	while (!s.empty()) {
		result += s.top().first;
		s.pop();
	}
	reverse(result.begin(), result.end());
	cout << result << "\n";

	return 0;
}