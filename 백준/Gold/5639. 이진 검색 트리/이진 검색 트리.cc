#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> tree(10000);

void postOrder(int start, int end) {
	if (start >= end) {
		return;
	}
	if (start == end - 1) {
		cout << tree[start] << "\n";
		return;
	}
	int root = tree[start];
	int branch_idx = start + 1;
	while (branch_idx < end) {
		if (root < tree[branch_idx]) {
			break;
		}
		branch_idx += 1;
	}
	postOrder(start + 1, branch_idx);
	postOrder(branch_idx, end);
	cout << tree[start] << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int num;
	int cur_idx = 0;
	while (cin >> num) {
		tree[cur_idx++] = num;
	}
	postOrder(0, cur_idx);

	return 0;
}