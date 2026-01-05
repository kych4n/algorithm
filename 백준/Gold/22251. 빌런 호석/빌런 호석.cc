#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

int N, K, P, X;
long long result = 0;
vector<int> bin = { 0b1101111, 0b0100100, 0b1110011,0b1110110,0b0111100,0b1011110,0b1011111,0b1100100,0b1111111,0b1111110 };
string xStr;

void bt(string current, int remainP) {
    if (current.length() == K) {
        int currentNumber = stoi(current);
        if (currentNumber >= 1 && currentNumber <= N && currentNumber != X) {
            result += 1;
        }
        return;
    }
    int curNumber = xStr[current.length()] - '0';
    for (int changeNumber = 0; changeNumber <= 9; changeNumber++) {
        int needP = bitset<7>(bin[curNumber] ^ bin[changeNumber]).count();
        if (remainP >= needP) {
            bt(current + to_string(changeNumber), remainP - needP);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> P >> X;

    xStr = to_string(X);
    int xLength = xStr.length();
    for (int i = 0; i < K - xLength; i++) {
        xStr = "0" + xStr;
    }

    bt("", P);

    cout << result << "\n";
    return 0;
}