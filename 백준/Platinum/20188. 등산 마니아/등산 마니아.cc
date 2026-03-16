#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
    한 오두막에서 다른 오두막으로 갈 때는 1번을 거치는 가장 짧은 길을 따라 간다. 
    모든 i번 오두막에서 j번 오두막으로 가는 길에 포함된 길의 개수의 총 합, 두 번 이상 지나간 길은 한 번만 센다는 것에 주의하라.

    - N=10^5, 1에서부터 깊이를 늘려가면서 거리를 갱신하고, dp[i][j] = dp[1][i] + dp[k][j]은 에바임
    - 길의 개수의 총합을 구해야 함 -> 길이 언제 사용되지 않는가? - i,j 간선이라면, j의 서브트리를 구성하는 노드
*/
typedef long long ll;
int N;
ll total_diversity = 0;
ll subtree_size[300001];
map<int, vector<int>> adj;

ll comb2(ll n) {
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