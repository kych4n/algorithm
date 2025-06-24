#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int borrowLeftFirst(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    vector<bool> remain(n+1);
    for (int i: reserve) {
        remain[i] = true;
    }
    for (int i: lost) {
        if (remain[i]) {
            remain[i] = false;
            answer += 1;
            continue;
        }
        if (i+1<=n && remain[i+1]) {
            remain[i+1] = false;
            answer += 1;
            continue;
        }
        if (i-1>=1 && remain[i-1]) {
            remain[i-1] = false;
            answer += 1;
        }
    }
    return answer;
}

int borrowRightFirst(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    vector<bool> remain(n+1);
    for (int i: reserve) {
        remain[i] = true;
    }
    for (int i: lost) {
        if (remain[i]) {
            remain[i] = false;
            answer += 1;
            continue;
        }
        if (i-1>=1 && remain[i-1]) {
            remain[i-1] = false;
            answer += 1;
            continue;
        }
        if (i+1<=n && remain[i+1]) {
            remain[i+1] = false;
            answer += 1;
        }
    }
    return answer;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> realLost;
    vector<int> realReserve;
    set_difference(lost.begin(), lost.end(), reserve.begin(), reserve.end(), back_inserter(realLost));
    set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), back_inserter(realReserve));
    int answer = max(borrowLeftFirst(n, realLost, realReserve), borrowRightFirst(n, realLost, realReserve));
    return answer;
}