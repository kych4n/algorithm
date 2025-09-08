#include <iostream>
#include <vector>
using namespace std;

string str;
int b_count = 0, result = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		if (str[i] == 'b') {
			b_count += 1;
		}
	}
	if (b_count == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < length; i++) {
		int current_b_count = 0;
		for (int j = 0; j < length; j++) {
			if (str[(i + j) % length] == 'b') {
				current_b_count += 1;
			}
			if (j + 1 >= b_count) {
				result = min(result, j + 1 - current_b_count);
			}
		}
	}
	cout << result << "\n";
	return 0;
}