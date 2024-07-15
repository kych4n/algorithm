#include <iostream>
#include <string>
#include <deque>
using namespace std;

int t, n, sign;
deque<int> dq;
string p, temp_list, temp_num;

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		sign = 0;
		cin >> p >> n >> temp_list;
		for (int j = 0; j < temp_list.length(); j++) {
			if (temp_list[j] == '[') {
				continue;
			}
			if (temp_list[j] == ',' || temp_list[j] == ']') {
				if (temp_num == "") {
					continue;
				}
				dq.push_back(stoi(temp_num));
				temp_num = "";
			}
			else {
				temp_num += temp_list[j];
			}
		}
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				if (sign == 1) {
					sign = 0;
				}
				else if (sign == 0) {
					sign = 1;
				}
			}
			else if (p[j] == 'D') {
				if (dq.empty()) {
					sign = 2;
					break;
				}
				if (sign == 0){
					dq.pop_front();
				}
				else if (sign == 1) {
					dq.pop_back();
				}
			}
		}
		int size = dq.size();
		if (sign == 0) {
			cout << "[";
			for (int j = 0; j < size; j++) {
				cout << dq.front();
				dq.pop_front();
				if (j < size - 1) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
		else if (sign == 1) {
			cout << "[";
			for (int j = 0; j < size; j++) {
				cout << dq.back();
				dq.pop_back();
				if (j < size - 1) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
		else if (sign == 2) {
			cout << "error" << "\n";
		}
	}
	return 0;
}