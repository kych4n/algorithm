#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(Point other) const {
        if (x < other.x) {
            return true;
        } else if (x == other.x) {
            return y < other.y;
        } else
            return false;
    }
};

vector<Point> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    sort(points.begin(), points.end());
    for (Point point: points) {
        cout << point.x << " " << point.y << "\n";
    }
    return 0;
}
