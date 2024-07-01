#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, target;
vector<int> numbers(100001);

bool binary_search(int target){
	int start = 0, end = n-1, mid;
	while (start <= end) {
		mid = (start+end)/2;
		if (numbers[mid] == target){
			return true;
		}
		else if (numbers[mid] < target){
			start = mid + 1;
		}
		else if (numbers[mid] > target) {
			end = mid - 1;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.begin()+n);	
	cin >> m;
	for (int j=0; j<m; j++){
		cin >> target;
		if (binary_search(target)){
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
	return 0;
}