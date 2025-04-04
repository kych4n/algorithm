#include <iostream>
#include <queue>
using namespace std;

class Meeting {
public:
    int start;
    int end;

    Meeting(int start, int end) {
        this->start = start;
        this->end = end;
    }

    bool operator<(const Meeting &other) const {
        if (end > other.end) {
            return true;
        } else if (end == other.end) {
            return start > other.start;
        } else {
            return false;
        }
    }
};

priority_queue<Meeting> pq;

int solve(int n) {
    int count = 0;
    int currentEnd = 0;
    while (!pq.empty()) {
        Meeting curruentMeeting = pq.top();
        pq.pop();
        if (curruentMeeting.start >= currentEnd) {
            currentEnd = curruentMeeting.end;
            count += 1;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, start, end;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        pq.emplace(start, end);
    }
    cout << solve(n) << "\n";
    return 0;
}
