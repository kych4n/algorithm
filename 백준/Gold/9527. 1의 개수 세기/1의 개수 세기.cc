#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll power2[60];

ll f(ll n) {
    if (n <= 0) return 0;
    if (n <= 1) return 1;

    ll k = 0;
    while ((1LL << (k + 1) <= n)) k++;

    ll result = (k * (1LL << (k - 1))) + (n - (1LL << k) + 1) + f(n - (1LL << k));
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B;
    cin >> A >> B;
    
    cout << f(B) - f(A - 1) << "\n";
    return 0;
}