#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, number, person, result = 0;
vector<int> parent(51);
vector<vector<int>> parties;

int find_parent(int x) {
	if (parent[x] != x) {
		return find_parent(parent[x]);
	}
	return x;
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	cin >> number;
	if (number == 0) {
		cout << m << "\n";
		return 0;
	}

	for (int i = 0; i < number; i++) {
		cin >> person;
		parent[person] = 0;
	}
	
	for (int i = 0; i < m; i++) {
		vector<int> party;
		cin >> number;
		for (int j = 0; j < number; j++) {
			cin >> person;
			party.push_back(person);
		}
		for (int j = 1; j < number; j++) {
			union_parent(party[0], party[j]);
		}
		parties.push_back(party);
	}

	int result = m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < parties[i].size(); j++) {
			if (find_parent(parties[i][j]) == 0) {
				result -= 1;
				break;
			}
		}
	}
	cout << result << "\n";

	return 0;
}