#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, age;
string name;

class Member {
public:
    int age;
    string name;

    Member(int age, string name) {
        this->age = age;
        this->name = name;
    }
};

vector<Member> members;

bool compare(Member a, Member b) {
    return a.age < b.age;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        members.emplace_back(age, name);
    }
    stable_sort(members.begin(), members.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << members[i].age << " " << members[i].name << "\n";
    }
    return 0;
}
