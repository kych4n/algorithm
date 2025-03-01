#include <iostream>
#include <vector>
using namespace std;

int n, number, MAX = 1e6;
vector<bool> numbers(2*MAX+1);

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> number;
        numbers[number+MAX] = true;
    }
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i]) {
            cout << i-MAX << "\n";
        }
    }
    return 0;
}