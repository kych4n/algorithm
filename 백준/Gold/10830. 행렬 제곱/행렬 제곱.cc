#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, B;
vector<vector<ll>> unit_matrix(5, vector<ll>(5));

vector<vector<ll>> multiple(vector<vector<ll>> first, vector<vector<ll>> second) {
	vector<vector<ll>> third(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				third[i][j] += first[i][k] * second[k][j];
			}
			third[i][j] %= 1000;
		}
	}
	return third;
}

vector<vector<ll>> find(vector<vector<ll>> matrix, ll B) {
	if (B == 0) {
		return unit_matrix;
	}
	if (B % 2 == 0) {
		vector<vector<ll>> half = find(matrix, B / 2);
		return multiple(half, half);
	}
	else if (B % 2 == 1) {
		return multiple(matrix, find(matrix, B - 1));
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> B;
	vector<vector<ll>> A(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			if (i == j) {
				unit_matrix[i][j] = 1;
			}
		}
	}
	
	vector<vector<ll>> result = find(A, B);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}