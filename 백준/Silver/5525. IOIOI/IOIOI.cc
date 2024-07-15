#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n, m;
string s;
int result = 0;

int main(void)
{
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int count = 0;
		if (s[i] == 'I') {
			while (true) {
				if (s[i + 1] == 'O' && s[i + 2] == 'I') {
					count += 1;
					i = i + 2;
				}
				else {
					break;
				}
			}
		}
		if (count+1-n>0){
			result += count+1-n;
		}
	}
	cout << result << "\n";
	return 0;
}