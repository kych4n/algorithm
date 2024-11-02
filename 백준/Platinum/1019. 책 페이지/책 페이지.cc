#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long N;
long long ans[10];

void calc(int n, int digit) {
	while (n > 0) {
		ans[n % 10] += digit;
		n /= 10;
	}
}

void sol(int A, int B, int digit) {
	while (A % 10 != 0 && A <= B) {
		calc(A, digit);
		A++;
	}

	if (A > B) return;

	while (B % 10 != 9 && A <= B) {
		calc(B, digit);
		B--;
	}

	long long temp = (B / 10 - A / 10 + 1);

	for (int i = 0; i < 10; i++)
		ans[i] += temp * digit;

	sol(A / 10, B / 10, digit * 10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	sol(1, N, 1);

	for (int i = 0; i < 10; i++)
		cout << ans[i] << ' ';

	return 0;
}