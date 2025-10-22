#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int A, B, C;
unordered_map<int, vector<pair<int, int>>> adj;
vector<int> min_cost(50001, 1e9 + 7);

void dijkstra() {
    min_cost[1] = 0;
    priority_queue<int> pq;
    pq.push(1);
    while (!pq.empty()) {
        int cur_loc = pq.top();
        pq.pop();
        int road_count = adj[cur_loc].size();
        for (int i = 0; i < road_count; i++) {
            int next_loc = adj[cur_loc][i].first;
            int need_cost = adj[cur_loc][i].second;
            if (min_cost[next_loc] > min_cost[cur_loc] + need_cost) {
                min_cost[next_loc] = min_cost[cur_loc] + need_cost;
                pq.push(next_loc);
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({ B, C });
        adj[B].push_back({ A, C });
    }

    dijkstra();

    cout << min_cost[N] << "\n";

    return 0;
}