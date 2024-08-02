#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> data;
	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		vector<int> v;
		v.push_back(r);
		v.push_back(g);
		v.push_back(b);
		data.push_back(v);
	}

	vector<vector<int>> save;
	for (int i = 0; i < n; i++) {
		vector<int> v(3, 1000*1000);
		save.push_back(v);
	}

	for (int i = 0; i < 3; i++) {
		save[0][i] = data[0][i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j != k && save[i][j] > save[i - 1][k] + data[i][j]) {
					save[i][j] = save[i - 1][k] + data[i][j];
				}
			}
		}
	}

	int result = 1000*1000;
	for (int i = 0; i < 3; i++) {
		if (result > save[n - 1][i]) {
			result = save[n - 1][i];
		}
	}
	cout << result << endl;
	return 0;
}