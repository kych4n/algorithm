#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

map<char, int> game_to_count = { {'Y', 2}, {'F', 3}, {'O',4} };
set<string> people;
string name;
char game;
int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> game;
	for (int i = 0; i < n; i++) {
		cin >> name;
		people.insert(name);
	}
	cout << people.size() / (game_to_count[game] - 1) << "\n";
	return 0;
}