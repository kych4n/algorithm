#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll f(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    ll temp_n = n;
    ll bit_count = 0;
    while (temp_n / 2 != 0) {
        bit_count++;
        temp_n /= 2;
    }
    
    return bit_count * (1LL << (bit_count - 1)) + (n - (1LL << bit_count) + 1) + f(n - (1LL << bit_count));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B;
    cin >> A >> B;
    cout << f(B) - f(A - 1) << "\n";

    return 0;
}