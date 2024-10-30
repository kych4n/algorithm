#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k, s, e, c;
vector<pair<int, int>> adj_matrix[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> cost_to_vertex[1001];

void Dijkstra(){
    pq.push({0, 1});
    cost_to_vertex[1].push(0);
    while (!pq.empty()){
        int cur_cost = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();
        for (int i=0; i<adj_matrix[cur_vertex].size(); i++){
            int new_cost = cur_cost + adj_matrix[cur_vertex][i].first;
            int new_vertex = adj_matrix[cur_vertex][i].second;
            if (cost_to_vertex[new_vertex].size() < k){
                cost_to_vertex[new_vertex].push(new_cost);
                pq.push({new_cost, new_vertex});
            }
            else if (cost_to_vertex[new_vertex].top() > new_cost) {
                cost_to_vertex[new_vertex].pop();
                cost_to_vertex[new_vertex].push(new_cost);
                pq.push({new_cost, new_vertex});
            }
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i=0; i<m; i++){
        cin >> s >> e >> c;
        adj_matrix[s].push_back({c, e});
    }

    Dijkstra();

    for (int i=1; i<=n; i++){
        if (cost_to_vertex[i].size() != k){
            cout << -1 << "\n";
        }
        else{
            cout << cost_to_vertex[i].top() << "\n";
        }
    }

    return 0;
}