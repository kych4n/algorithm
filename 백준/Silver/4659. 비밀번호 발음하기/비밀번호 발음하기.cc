#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string str;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> str) {
		if (str == "end") {
			break;
		}
		bool cond1 = false;
		bool cond2 = true;
		bool cond3 = true;
		int vowel_count = 0;
		int consonant_count = 0;
		int sequence_count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				cond1 = true;
				vowel_count += 1;
				consonant_count = 0;
			}
			else if (str[i] != ' ') {
				consonant_count += 1;
				vowel_count = 0;
			}
			if (vowel_count == 3 || consonant_count == 3) {
				cond2 = false;
			}
			if (i > 0 && str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o') {
				cond3 = false;
			}
		}

		if (cond1 && cond2 && cond3) {
			cout << "<" << str << "> is acceptable.\n";
		}
		else {
			cout << "<" << str << "> is not acceptable.\n";
		}
	}
	
	
	return 0;
}
