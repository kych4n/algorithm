#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;	
int t;
string Start, End;
bool possible = false;

void solve(string cur_End){
	if (cur_End.back() == 'X'){
		string new_End = cur_End.substr(0, cur_End.length()-1);
		if (new_End == Start){
			possible = true;
			return;
		}
		else{
			solve(new_End);
		}
	}
	if (cur_End.front() == 'Y') {
		string new_End = cur_End.substr(1, cur_End.length()-1);
		reverse(new_End.begin(), new_End.end());
		if (new_End == Start){
			possible = true;
			return;
		}
		else{
			solve(new_End);
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int i=1; i<=t; i++){
		possible = false;
		cin >> Start >> End;
		solve(End);
		cout << "#" << i << " ";
		if (possible){
			cout << "Yes" << "\n";
		}
		else{
			cout << "No" << "\n";
		}
	}

	return 0;
}