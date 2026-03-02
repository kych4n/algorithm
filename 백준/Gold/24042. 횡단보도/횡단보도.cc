#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 4e18;

struct Edge {
    int to;
    int offset;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
    }

    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        ll cur_time = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_time) continue;
        if (cur_node == N) break;

        for (auto& edge : adj[cur_node]) {
            ll wait = (edge.offset - (cur_time % M) + M) % M;
            ll next_time = cur_time + wait + 1;

            if (dist[edge.to] > next_time) {
                dist[edge.to] = next_time;
                pq.push({ next_time, edge.to });
            }
        }
    }

    cout << dist[N] << "\n";

    return 0;
}