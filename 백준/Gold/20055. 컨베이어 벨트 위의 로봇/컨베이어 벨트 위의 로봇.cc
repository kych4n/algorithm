#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, stage = 0, zero_count = 0;

int get_target(int idx) {
	int temp = (idx - stage % (2 * n));
	if (temp < 0) {
		temp += 2 * n;
	}
	return temp;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vector<int> remain_power(2 * n);
	vector<bool> robot_located(n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> remain_power[i];
	}

	while (true) {
		stage += 1;

		// 1. 벨트 한 칸 이동
		for (int j = n - 2; j > 0; j--) {
			robot_located[j] = robot_located[j - 1];
		}
		robot_located[0] = false;

		// 2. 컨베이어 벨트 뒤에서부터 그 칸의 내구도 여부에 따라 옮기기
		int target = get_target(n - 1);
		if (robot_located[n - 2] && remain_power[target] > 0) {
			robot_located[n - 2] = false;
			remain_power[target] -= 1;
			if (remain_power[target] == 0) {
				zero_count += 1;
			}
		}
		
		for (int j = n - 3; j >= 0; j--) {
			int target = get_target(j + 1);
			if (robot_located[j] && !robot_located[j + 1] && remain_power[target] > 0) {
				robot_located[j] = false;
				robot_located[j + 1] = true;
				remain_power[target] -= 1;
				if (remain_power[target] == 0) {
					zero_count += 1;
				}
			}
		}

		// 올리기
		target = get_target(0);
		if (!robot_located[0] && remain_power[target] > 0) {
			robot_located[0] = true;
			remain_power[target] -= 1;
			if (remain_power[target] == 0) {
				zero_count += 1;
			}
		}

		if (zero_count >= k) {
			break;
		}

	}

	cout << stage << "\n";

	return 0;
}