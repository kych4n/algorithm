#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int t, n, m;
vector<int> a(1000);
vector<long long> aSum(1000);
vector<int> b(1000);
vector<long long> bSum(1000);
map<int, long long> aMap;
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
        if (aMap.find(aSum[i]) != aMap.end()) {
				aMap[aSum[i]] += 1;
			}
			else {
				aMap.insert({ aSum[i] , 1 });
			}
   
		for (int j = 0; j < i; j++) {
			long long part_sum = aSum[i] - aSum[j];
			if (aMap.find(aSum[i] - aSum[j]) != aMap.end()) {
				aMap[part_sum] += 1;
			}
			else {
				aMap.insert({ part_sum, 1 });
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		if (aMap.find(t - bSum[i]) != aMap.end()) {
			result += aMap[t - bSum[i]];
		}
		for (int j = 0; j < i; j++) {
			long long part_sum = bSum[i] - bSum[j];
			if (aMap.find(t - part_sum) != aMap.end()) {
				result += aMap[t - part_sum];
			}
		}
	}

	cout << result << "\n";

	return 0;
}
