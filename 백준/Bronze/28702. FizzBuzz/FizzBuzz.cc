#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;

string check(int n) {
	if (n % 3 == 0 && n % 5 == 0) {
		return "FizzBuzz";
	}
	else if (n % 3 == 0) {
		return "Fizz";
	}
	else if (n % 5 == 0) {
		return "Buzz";
	}
	else return to_string(n);
}

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 3; i++) {
		cin >> s;
		if (isdigit(s[0])) {
			cout << check(stoi(s) + 3 - i) << "\n";
			return 0;
		}
	}

	return 0;
}