#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, result;
int arr[100001];
bool visited[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	result = N * (N + 1) / 2;
	int left = 0, right = 1;
	visited[arr[0]] = true;

	while (right < N) {
		if (visited[arr[right]]) {
			visited[arr[left]] = false;
			left++;
			result -= (N - right);
		}
		else {
			visited[arr[right]] = true;
			right++;
		}
	}

	cout << result << "\n";

	return 0;
}