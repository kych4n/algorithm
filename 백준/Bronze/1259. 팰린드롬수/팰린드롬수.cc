#include <iostream>
using namespace std;

string number, result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        result = "yes";
        cin >> number;
        if (number == "0") {
            break;
        }
        int last_idx = number.length()-1;
        for (int i=0; i<number.length()/2; i++) {
            if (number[i] != number[last_idx-i]) {
                result = "no";
                break;
            }
        }
        cout << result << "\n";
    }

    return 0;
}