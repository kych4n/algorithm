#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> p;

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	p = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	int temp_sum = 0;
	int result = 0;
	for (int i = 0; i < n; i++) {
		temp_sum += p[i];
		result += temp_sum;
	}
	cout << result << "\n";
	
	return 0;
}