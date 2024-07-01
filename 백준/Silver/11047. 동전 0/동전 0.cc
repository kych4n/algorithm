#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, result = 0;
vector<int> coins(10);

int main() {
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> coins[i];
	}
	for (int i=n-1; i>=0; i--){
		result += k / coins[i];
		k %= coins[i];
	}
	cout << result << "\n";
	return 0;
}