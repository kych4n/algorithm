#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<string, vector<string>> group_to_member;
map<string, string> member_to_group;
int n, m, k;
string group, member, quiz;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> group >> k;
		for (int j = 0; j < k; j++) {
			cin >> member;
			group_to_member[group].push_back(member);
			member_to_group[member] = group;
		}
	}

	for (auto iter = group_to_member.begin(); iter != group_to_member.end(); iter++) {
		sort(iter->second.begin(), iter->second.end());
	}
	
	for (int i = 0; i < m; i++) {
		cin >> quiz >> k;
		if (k == 0) {
			for (int j = 0; j < group_to_member[quiz].size(); j++) {
				cout << group_to_member[quiz][j] << "\n";
			}
		}
		else {
			cout << member_to_group[quiz] << "\n";
		}
	}
	return 0;
}
