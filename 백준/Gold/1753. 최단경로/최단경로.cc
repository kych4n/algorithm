#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

/*
    [입력] 노드 개수, 간선 개수, 시작 노드, 간선 정보
    [출력] 시작 노드에서 다른 노드로 가는 최소 거리
    간선의 가중치가 양수이므로 다익스트라
*/

const int INF = 1e9 + 7;
int V, E, K;
int u, v, w;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;
    vector<int> dist(V + 1, INF);
    vector<vector<pair<int, int>>> edges(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[u].push_back({ v, w });
    }

    dist[K] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, K });
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_cost) continue;

        for (auto p : edges[cur_node]) {
            int next_node = p.first;
            int cost = p.second;
            if (dist[next_node] > cur_cost + cost) {
                dist[next_node] = cur_cost + cost;
                pq.push({ dist[next_node], next_node });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}