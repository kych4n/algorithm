#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int t, n, m, part_sum;
vector<int> a(1000);
vector<int> aSum(1000);
vector<int> b(1000);
vector<int> bSum(1000);
vector<int> partSumA;
long long result = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			aSum[i] = a[i] + aSum[i - 1];
		}
		else {
			aSum[i] = a[i];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (i > 0) {
			bSum[i] = b[i] + bSum[i - 1];
		}
		else {
			bSum[i] = b[i];
		}
	}

	for (int i = 0; i < n; i++) {
		partSumA.push_back(aSum[i]);
		for (int j = 0; j < i; j++) {
			partSumA.push_back(aSum[i] - aSum[j]);
		}
	}

	sort(partSumA.begin(), partSumA.end());

	for (int i = 0; i < m; i++) {
		result += upper_bound(partSumA.begin(), partSumA.end(), t - bSum[i]) -lower_bound(partSumA.begin(), partSumA.end(), t - bSum[i]);
		for (int j = 0; j < i; j++) {
			part_sum = bSum[i] - bSum[j];
			result += upper_bound(partSumA.begin(), partSumA.end(), t - part_sum) - lower_bound(partSumA.begin(), partSumA.end(), t - part_sum);
		}
	}

	cout << result << "\n";

	return 0;
}
