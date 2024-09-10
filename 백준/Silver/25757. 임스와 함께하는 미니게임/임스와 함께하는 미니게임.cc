#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
char game;
string player;
set<string> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> game;
	for (int i = 0; i < n; i++) {
		cin >> player;
		s.insert(player);
	}
	
	if (game == 'Y') {
		cout << s.size() << "\n";
	}
	else if (game == 'F') {
		cout << s.size() / 2<< "\n";
	}
	else if (game == 'O') {
		cout << s.size() / 3 << "\n";
	}
	return 0;
}
