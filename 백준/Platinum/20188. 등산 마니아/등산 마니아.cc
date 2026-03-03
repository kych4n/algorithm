#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll total_diversity = 0;
ll subtree_size[300001];
map<int, vector<int>> adj;

ll comb2(ll n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}

void dfs(int cur, int prev) {
    subtree_size[cur] = 1;

    for (int next : adj[cur]) {
        if (next == prev) continue;

        dfs(next, cur);
        subtree_size[cur] += subtree_size[next];

        total_diversity += comb2(N) - comb2(N - subtree_size[next]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << total_diversity << "\n";
    
    return 0;
}