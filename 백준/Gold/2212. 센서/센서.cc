#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> sensors(n);
	for (int i = 0; i < n; i++) {
		cin >> sensors[i];
	}
	sort(sensors.begin(), sensors.end());

	vector<int> distances;
	for (int i = 0; i < n-1; i++) {
		distances.push_back(abs(sensors[i] - sensors[i + 1]));
	}

	sort(distances.begin(), distances.end());

	int result = 0;
	for (int i = 0; i < n - k; i++) {
		result += distances[i];
	}

	cout << result << endl;

	return 0;
}