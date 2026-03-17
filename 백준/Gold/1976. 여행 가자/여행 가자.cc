#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
    도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부를 판별
    - 최단 거리 아님, 그냥 가능 여부를 물어보고 있으므로, 한 덩어리로 뭉쳐있으면 됨
    - 
*/
int N, M;
int adj[200][200];
int parent[200];

int find_parent(int x) {
    if (parent[x] != x) {
        return find_parent(parent[x]);
    }
    return parent[x];
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x < y) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (adj[i][j]) union_parent(i, j);
        }
    }

    int dest;
    set<int> s;
    for (int i = 0; i < M; i++) {
        cin >> dest;
        dest--;
        s.insert(find_parent(dest));
    }

    if (s.size() == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}