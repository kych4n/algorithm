#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v, e, a, b, c, result = 0;
vector<int> parent(10001);
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;

int find_parent(int x) {
	if (parent[x] != x) {
		return find_parent(parent[x]);
	}
	return x;
}

void union_parent(int a, int b) {
	if (a > b) {
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

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edges.push({ c, a, b });
	}

	while (!edges.empty()) {
		int c = edges.top()[0];
		int a = edges.top()[1];
		int b = edges.top()[2];
		edges.pop();

		a = find_parent(a);
		b = find_parent(b);

		if (a != b) {
			union_parent(a, b);
			result += c;
		}
	}

	cout << result << "\n";

	return 0;
}