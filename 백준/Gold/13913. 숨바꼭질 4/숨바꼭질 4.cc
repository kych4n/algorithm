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
	vector<int> vparents(100001);
	vector<int> vresult(1, k);

	while (qloc.empty() == false && qtime.empty() == false) {
		int cur_loc = qloc.front();
		int cur_time = qtime.front();

		if (cur_loc * 2 <= 100000) {
			if (vtime[cur_loc * 2] > cur_time + 1) {
				vtime[cur_loc * 2] = cur_time + 1;
				qloc.push(cur_loc * 2);
				qtime.push(cur_time + 1);
				vparents[cur_loc * 2] = cur_loc;
			}
		}

		if (cur_loc + 1 <= 100000) {
			if (vtime[cur_loc + 1] > cur_time + 1) {
				vtime[cur_loc + 1] = cur_time + 1;
				qloc.push(cur_loc + 1);
				qtime.push(cur_time + 1);
				vparents[cur_loc + 1] = cur_loc;
			}
		}

		if (cur_loc - 1 >= 0) {
			if (vtime[cur_loc - 1] > cur_time + 1) {
				vtime[cur_loc - 1] = cur_time + 1;
				qloc.push(cur_loc - 1);
				qtime.push(cur_time + 1);
				vparents[cur_loc - 1] = cur_loc;
			}
		}
		qloc.pop();
		qtime.pop();
	}

	int answer = vtime[k];
	cout << answer << endl;

	for (int i = 0; i < answer; i++) {
		vresult.push_back(vparents[k]);
		k = vparents[k];
	}

	for (int i = vresult.size() - 1; i > -1; i--) {
		cout << vresult[i] << " ";
	}

	return 0;
}