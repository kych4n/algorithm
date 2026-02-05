#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Info {
	int min_number = 1e9 + 7;
	int visible_count = 0;
};

int N;
vector<int> height;
vector<Info> info;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	height.resize(N);
	info.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	// left -> right
	stack<pair<int, int>> s1;
	s1.push({ height[N - 1], N - 1 });
	for (int i = N - 2; i >= 0; i--) {
		while (!s1.empty() && height[i] >= s1.top().first) {
			s1.pop();
		}
		info[i].visible_count += s1.size();
		if (!s1.empty()) {
			info[i].min_number = min(info[i].min_number, s1.top().second);
		}
		s1.push({ height[i], i });
	}

	// right -> left
	stack<pair<int, int>> s2;
	s2.push({ height[0], 0 });
	for (int i = 1; i < N; i++) {
		while (!s2.empty() && height[i] >= s2.top().first) {
			s2.pop();
		}
		info[i].visible_count += s2.size();
		if (!s2.empty()) {
			if (abs(info[i].min_number - i) >= abs(s2.top().second - i)) {
				info[i].min_number = min(info[i].min_number, s2.top().second);
			}
		}
		s2.push({ height[i], i });
	}

	for (int i = 0; i < N; i++) {
		if (info[i].visible_count == 0) {
			cout << info[i].visible_count << "\n";
		}
		else {
			cout << info[i].visible_count << " " << info[i].min_number + 1 << "\n";
		}
	}

	return 0;
}