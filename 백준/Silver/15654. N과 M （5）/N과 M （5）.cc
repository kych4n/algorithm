#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> number(8);
vector<bool> visited(8);
vector<int> temp;

void bt(int count) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
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
	
	return 0;
}