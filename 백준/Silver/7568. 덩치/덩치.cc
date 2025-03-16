#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    int weight;
    int height;
};

int n;
vector<Person> people(50);

void solve() {
    for (int i = 0; i < n; i++) {
        int rating = 1;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (people[i].weight < people[j].weight && people[i].height < people[j].height) {
                rating += 1;
            }
        }
        cout << rating << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> people[i].weight >> people[i].height;
    }
    solve();
    return 0;
}
