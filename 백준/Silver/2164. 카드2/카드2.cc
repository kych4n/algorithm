#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n;
deque<int> cards;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cards.push_back(i);
	}
	while (cards.size() > 1) {
		cards.pop_front();
		cards.push_back(cards.front());
		cards.pop_front();
	}
	cout << cards.front() << "\n";
	return 0;
}