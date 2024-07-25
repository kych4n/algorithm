#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, temp;
vector<vector<int>> adj_matrix(100, vector<int>(100));

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj_matrix[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adj_matrix[i][k] != 0 && adj_matrix[k][j] != 0) {
					adj_matrix[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << adj_matrix[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}