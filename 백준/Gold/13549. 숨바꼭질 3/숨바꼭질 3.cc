#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> vtime(100001, 100001);
	queue<int> qloc;
	queue<int> qtime;
	vtime[n] = 0;
	qloc.push(n);
	qtime.push(vtime[n]);
	
	while (qloc.empty() == false && qtime.empty() == false) {
		int cur_loc = qloc.front();
		int cur_time = qtime.front();

		if (cur_loc * 2 <= 100000) {
			if (vtime[cur_loc * 2] > cur_time) {
				vtime[cur_loc * 2] = cur_time;
				qloc.push(cur_loc * 2);
				qtime.push(cur_time);
			}

		}

		if (cur_loc + 1 <= 100000) {
			if (vtime[cur_loc + 1] > cur_time + 1) {
				vtime[cur_loc + 1] = cur_time + 1;
				qloc.push(cur_loc + 1);
				qtime.push(cur_time + 1);
			}
		}

		if (cur_loc - 1 >= 0) {
			if (vtime[cur_loc - 1] > cur_time + 1) {
				vtime[cur_loc - 1] = cur_time + 1;
				qloc.push(cur_loc - 1);
				qtime.push(cur_time + 1);
			}
		}  
		qloc.pop();
		qtime.pop();
	}

	cout << vtime[k] << endl;

	return 0;
}