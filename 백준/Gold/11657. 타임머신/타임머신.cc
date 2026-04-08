#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    [입력] A, B, C 노선이 주어짐, C는 음수일 수도, 0일 수도 있음
    [출력] 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간
           - 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1 
           - 그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력한다. 
           - 만약 해당 도시로 가는 경로가 없다면 대신 -1을 출력한다.

    경로의 비용이 0과 음수일 수 있다는 것이 문제 -> 벨만 포드
*/

struct Edge {
    int start, end, cost;
    Edge(int start, int end, int cost) {
        this->start = start;
        this->end = end;
        this->cost = cost;
    }
};

int N, M, A, B, C;
const int INF = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edges.push_back(Edge(A, B, C));
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    bool has_cycle = false;
    for (int i = 1; i <= N; i++) {
        for (const Edge& e : edges) {
            if (dist[e.start] == INF) continue;
            if (dist[e.end] > dist[e.start] + e.cost) {
                dist[e.end] = dist[e.start] + e.cost;
                if (i == N) {
                    has_cycle = true;
                    break;
                }
            }
        }
    }

    if (has_cycle) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}