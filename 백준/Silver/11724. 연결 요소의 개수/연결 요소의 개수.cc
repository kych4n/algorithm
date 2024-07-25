#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m, u, v;
vector<int> parent(1001);
set<int> result;

int find_parent(int x) {
	if (parent[x] != x) {
		return find_parent(parent[x]);
	}
	return parent[x];
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

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		union_parent(u, v);
	}
	
	for (int i = 1; i <= n; i++) {
		result.insert(find_parent(i));
	}
	cout << result.size() << "\n";

	return 0;
}