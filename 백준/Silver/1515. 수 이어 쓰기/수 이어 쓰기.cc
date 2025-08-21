#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int current_num = 1;
int current_idx = 0;
string number;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> number;
	while (current_idx < number.size()) {
		string current_num_string = to_string(current_num);
		for (int j = 0; j < current_num_string.size(); j++) {
			if (number[current_idx] == current_num_string[j]) {
				current_idx += 1;
			}
		}
		current_num += 1;
	}
	cout << current_num - 1 << "\n";
	return 0;
}