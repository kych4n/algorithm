#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N;
map<char, pair<char, char>> adj;

void preorder(char c) {
    if (c == '.') return;
    cout << c;
    preorder(adj[c].first);
    preorder(adj[c].second);
}

void inorder(char c) {
    if (c == '.') return;
    inorder(adj[c].first);
    cout << c;
    inorder(adj[c].second);
}

void postorder(char c) {
    if (c == '.') return;
    postorder(adj[c].first);
    postorder(adj[c].second);
    cout << c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        adj[root] = { left, right };
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    
    return 0;
}