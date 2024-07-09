#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, m;
string name;
map<string, int> mm;
vector<string> result;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> name;
		mm.insert({name, 1});
	}
	for (int i=0; i<m; i++){
		cin >> name;
		if (mm.find(name) != mm.end()){
			result.push_back(name);		
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i=0; i<result.size(); i++){
		cout << result[i] << "\n";
	}
	return 0;
}