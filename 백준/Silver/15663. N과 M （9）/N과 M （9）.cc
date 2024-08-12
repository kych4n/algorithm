#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> number(8);
vector<bool> visited(8);
vector<int> temp;
vector<vector<int>> result;

void bt(int count) {
	if (count == m) {
		result.push_back(temp);
	}
	int same_level_last = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && same_level_last != number[i]) {
			same_level_last = number[i];
			visited[i] = true;
			temp.push_back(number[i]);
			bt(count + 1);
			temp.pop_back();
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number.begin(), number.begin() + n);
	
	bt(0);

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}