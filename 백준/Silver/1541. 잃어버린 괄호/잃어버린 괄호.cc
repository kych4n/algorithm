#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
string str, temp = "";
bool minus_appeared = false;
int result = 0;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	str += '+';
	for (int i=0; i<str.length(); i++){
		if (!(str[i] == '+' || str[i] == '-')){
			temp += str[i];
		}
		else {
			if (minus_appeared){
				result -= stoi(temp);
			}
			else{
				result += stoi(temp);
			}
			if (str[i] == '-'){
				minus_appeared = true;
			}
			temp = "";
		}
	}
	cout << result << "\n";
	return 0;
}