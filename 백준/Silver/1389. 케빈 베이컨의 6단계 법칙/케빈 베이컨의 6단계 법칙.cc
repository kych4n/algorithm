#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b;
vector<vector<int> > graph(101);
vector<int> kbNumbers;

int getKbNumber(int start) {
    vector<int> dist(n + 1, 100);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int curFriend = graph[cur][i];
            if (dist[curFriend] > dist[cur] + 1) {
                dist[curFriend] = dist[cur] + 1;
                q.push(curFriend);
            }
        }
    }

    int kbNumber = 0;
    for (int other = 1; other <= n; other++) {
        kbNumber += dist[other];
    }
    return kbNumber;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    kbNumbers.push_back(1e9 + 7);
    for (int start = 1; start <= n; start++) {
        kbNumbers.push_back(getKbNumber(start));
    }
    int minValueUser = 1;
    for (int user = 1; user <= n; user++) {
        if (kbNumbers[minValueUser] > kbNumbers[user]) {
            minValueUser = user;
        }
    }
    cout << minValueUser << "\n";
    return 0;
}
