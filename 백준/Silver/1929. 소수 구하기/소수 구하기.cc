#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int m, n;
int UPPER_LIMIT = 1000000;
vector<bool> is_not_prime(UPPER_LIMIT + 1);

void determine_prime() {
    is_not_prime[1] = true;
    for (int i = 2; i <= floor(sqrt(UPPER_LIMIT)); i++) {
        for (int j = 2; j < i - 1; j++) {
            if (i % j == 0) {
                is_not_prime[i] = true;
                break;
            }
        }
        if (!is_not_prime[i]) {
            for (int j = i + i; j <= UPPER_LIMIT; j = j + i) {
                is_not_prime[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    determine_prime();
    for (int i = m; i <= n; i++) {
        if (!is_not_prime[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
