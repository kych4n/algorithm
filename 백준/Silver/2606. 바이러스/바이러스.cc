#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > linked(101);

int solve() {
    vector<int> infected(101);
    infected[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curCom = q.front();
        q.pop();
        for (int nextCom: linked[curCom]) {
            if (!infected[nextCom]) {
                infected[nextCom] = 1;
                q.push(nextCom);
            }
        }
    }
    int infectedCount = -1;
    for (int infectedCom: infected) {
        infectedCount += infectedCom;
    }
    return infectedCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, com1, com2;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> com1 >> com2;
        linked[com1].push_back(com2);
        linked[com2].push_back(com1);
    }
    cout << solve() << "\n";
    return 0;
}
