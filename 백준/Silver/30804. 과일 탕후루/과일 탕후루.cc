#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, fruit, type = 0, result = 0;
vector<int> fruit_count(10);
queue<int> stick;

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> fruit;
		stick.push(fruit);

		if (fruit_count[fruit] == 0) {
			type += 1;
		}
		fruit_count[fruit] += 1;

		while (type > 2) {
			int front_fruit = stick.front();
			stick.pop();
			fruit_count[front_fruit] -= 1;
			if (fruit_count[front_fruit] == 0) {
				type -= 1;
			}
		}
		
		result = max(result,(int)stick.size());
	}
	cout << result << "\n";

	return 0;
}