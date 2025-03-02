#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string word;
set<string> words_set;

bool compare(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    } else if (a.length() == b.length()) {
        return a < b;
    }
    else {
        return false;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> word;
        words_set.insert(word);
    }
    vector<string> words_vector(words_set.begin(), words_set.end());
    sort(words_vector.begin(), words_vector.end(), compare);
    for (string word : words_vector) {
        cout << word << "\n";
    }
    return 0;
}