#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a, b;
long long arr[55];

long long f(long long x) {
	long long result = x & 1;
	for (long long i = 54; i > 0; i--) {
		if (x & (1LL << i)) {
			result += arr[i - 1] + (x - (1LL << i) + 1);
			x -= (1LL << i);
		}
	}
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b;

	arr[0] = 1;
	for (int i = 1; i < 55; i++) {
		arr[i] = arr[i - 1] + (1LL << i) + arr[i - 1];
	}

	cout << f(b) - f(a - 1) << "\n";

	return 0;
}
