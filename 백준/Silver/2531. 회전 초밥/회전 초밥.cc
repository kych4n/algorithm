#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, d, k, c, result = 0, not_duplicated_count = 0;
vector<int> current_count(3001);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> d >> k >> c;
	vector<int> sushi(n);
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	queue<int> sequence;
	for (int i = 0; i < n + k; i++) {
		int target_number = sushi[i % n];
		if (sequence.size() < k) {
			if (current_count[target_number] == 0) {
				not_duplicated_count += 1;
			}
			sequence.push(target_number);
			current_count[target_number] += 1;
		}
		if (sequence.size() == k) {
			if (current_count[c] == 0) {
				result = max(result, not_duplicated_count + 1);
			}
			else {
				result = max(result, not_duplicated_count);
			}
			current_count[sequence.front()] -= 1;
			if (current_count[sequence.front()] == 0) {
				not_duplicated_count -= 1;
			}
			sequence.pop();
		}
	}
	cout << result << "\n";
	return 0;
}