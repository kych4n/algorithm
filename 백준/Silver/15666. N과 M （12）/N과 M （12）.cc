#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, temp;
vector<int> number;
vector<int> result;

void bt(int count, int last_idx) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = last_idx; i < n; i++) {
		result.push_back(number[i]);
		bt(count + 1, i);
		result.pop_back();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		number.push_back(temp);
	}
	
	sort(number.begin(), number.end());
	number.erase(unique(number.begin(), number.end()), number.end());
	n = number.size();

	bt(0, 0);
	
	return 0;
}