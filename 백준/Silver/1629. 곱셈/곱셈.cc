#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long a, b, c;

long long square(long long b) {
	if (b == 0) {
		return 1;
	}
	else if (b % 2 == 0) {
		long long half = square(b / 2);
		return half * half % c;
	}
	else if (b % 2 == 1) {
		return square(b - 1) * a % c;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c;

	cout << square(b) << "\n";

	return 0;
}