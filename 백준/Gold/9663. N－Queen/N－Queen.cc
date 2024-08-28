#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, result = 0;
vector<int> col(15);

bool check(int cur_row) {
	for (int i = 1; i < cur_row; i++) {
		if (col[i] == col[cur_row]) {
			return false;
		}
		if (cur_row - i == abs(col[i] - col[cur_row])) {
			return false;
		}
	}
	return true;

}

void nqueen(int cur_row) {
	if (cur_row == n + 1) {
		result += 1;
		return;
	}

	for (int i = 1; i <= n; i++) {
		col[cur_row] = i;
		if (check(cur_row)) {
			nqueen(cur_row + 1);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> n;

	nqueen(1);

	cout << result << "\n";
	
	return 0;
}