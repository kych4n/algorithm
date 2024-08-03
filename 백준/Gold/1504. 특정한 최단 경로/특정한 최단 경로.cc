#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Info {
public:
	int cost;
	int x;
	bool v1_ok;
	bool v2_ok;
	Info(int cost, int x, bool v1_ok, bool v2_ok) {
		this->cost = cost;
		this->x = x;
		this->v1_ok = v1_ok;
		this->v2_ok = v2_ok;
	}
};

struct compare {
	bool operator() (Info a, Info b){
		return a.cost > b.cost;
	}
};

int n, e, a, b, c, v1, v2;
vector<vector<pair<int, int>>> adj_list(801);
vector<vector<int>> dist(801, vector<int>(4, 1e9 + 7));
priority_queue<Info, vector<Info>, compare> pq;

void dijkstra() {
	if (1 == v1) {
		pq.push(Info(0, 1, true, false));
	}
	else {
		pq.push(Info(0, 1, false, false));
	}
	
	dist[1][0] = 0;
	while (!pq.empty()) {
		Info cur_info = pq.top();
		pq.pop();
		int cur_cost = cur_info.cost;
		int cur_x = cur_info.x;
		bool cur_v1_ok = cur_info.v1_ok;
		bool cur_v2_ok = cur_info.v2_ok;
		for (int i = 0; i < adj_list[cur_x].size(); i++) {
			int next_cost = cur_cost + adj_list[cur_x][i].first;
			int next_x = adj_list[cur_x][i].second;
			bool next_v1_ok = cur_v1_ok;
			bool next_v2_ok = cur_v2_ok;
			if (next_x == v1) {
				next_v1_ok = true;
			}
			if (next_x == v2) {
				next_v2_ok = true;
			}

			if (!next_v1_ok && !next_v2_ok && dist[next_x][0] > next_cost) {
				dist[next_x][0] = next_cost;
				pq.push(Info(next_cost, next_x, next_v1_ok, next_v2_ok));
			}
			else if (!next_v1_ok && next_v2_ok && dist[next_x][1] > next_cost) {
				dist[next_x][1] = next_cost;
				pq.push(Info(next_cost, next_x, next_v1_ok, next_v2_ok));
			}
			else if (next_v1_ok && !next_v2_ok && dist[next_x][2] > next_cost) {
				dist[next_x][2] = next_cost;
				pq.push(Info(next_cost, next_x, next_v1_ok, next_v2_ok));
			}
			else if (next_v1_ok && next_v2_ok && dist[next_x][3] > next_cost) {
				dist[next_x][3] = next_cost;
				pq.push(Info(next_cost, next_x, next_v1_ok, next_v2_ok));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ c, b });
		adj_list[b].push_back({ c, a });
	}
	cin >> v1 >> v2;
	
	dijkstra();

	if (dist[n][3] >= 1e9 + 7) {
		cout << -1 << "\n";
	}
	else {
		cout << dist[n][3] << "\n";
	}


	return 0;
}