#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, K;
deque<int> durability;
deque<bool> is_on;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int d; cin >> d;
		durability.push_back(d);
		is_on.push_back(false);
	}

	int stage = 1;
	int unavailable_count = 0;

	while (true) {
		durability.push_front(durability.back());
		durability.pop_back();
		is_on.push_front(is_on.back());
		is_on.pop_back();

		is_on[N - 1] = false;

		for (int i = N - 2; i >= 0; i--) {
			if (is_on[i]) {
				int next = i + 1;
				if (!is_on[next] && durability[next] > 0) {
					is_on[i] = false;
					is_on[next] = true;
					durability[next]--;
					if (durability[next] == 0) {
						unavailable_count++;
					}
				}
			}
		}

		is_on[N - 1] = false;

		if (durability[0] > 0) {
			is_on[0] = true;
			durability[0]--;
			if (durability[0] == 0) {
				unavailable_count++;
			}
		}

		if (unavailable_count >= K) break;
		stage++;
	}
	
	cout << stage << "\n";
	return 0;
}