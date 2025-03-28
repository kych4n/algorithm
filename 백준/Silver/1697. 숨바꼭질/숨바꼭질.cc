#include <iostream>
#include <queue>
using namespace std;

int n, k, MAX_LOCATION = 100000, MIN_LOCATION = 0, MAX_VALUE = 1e9 + 7;
vector<int> minTime(MAX_LOCATION + 1, MAX_VALUE);

int forward(int start) {
    return start + 1;
}

int backward(int start) {
    return start - 1;
}

int teleport(int start) {
    return start * 2;
}

void solve(int start) {
    int currentTime = 0;
    minTime[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        currentTime += 1;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();
            int forwardLocation = forward(current);
            int backwardLocation = backward(current);
            int teleportLocation = teleport(current);
            if (forwardLocation <= MAX_LOCATION && currentTime < minTime[forwardLocation]) {
                minTime[forwardLocation] = currentTime;
                q.push(forwardLocation);
            }
            if (backwardLocation >= MIN_LOCATION && currentTime < minTime[backwardLocation]) {
                minTime[backwardLocation] = currentTime;
                q.push(backwardLocation);
            }
            if (teleportLocation <= MAX_LOCATION && currentTime < minTime[teleportLocation]) {
                minTime[teleportLocation] = currentTime;
                q.push(teleportLocation);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    solve(n);
    cout << minTime[k] << "\n";
    return 0;
}
