#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, m;
string name, target;
map<string, int> dogam1;
map<int, string> dogam2;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> name;
		dogam1.insert({name, i});
		dogam2.insert({i, name});
	}
	for (int i=1; i<=m; i++){
		cin >> target;
		if (dogam1.find(target) == dogam1.end()) {
			cout << dogam2.find(stoi(target))->second << "\n";
		}
		else{
			cout << dogam1.find(target)->second << "\n";
		}
	}
	
	return 0;
}