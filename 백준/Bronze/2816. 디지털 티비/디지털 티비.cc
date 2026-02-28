#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, kbs1_loc, kbs2_loc;
    cin >> N;
    vector<string> channel(N);
    for (int i = 0; i < N; i++) {
        cin >> channel[i];
        if (channel[i] == "KBS1") {
            kbs1_loc = i;
        }
    }

    for (int i = 0; i < kbs1_loc; i++) {
        cout << 1;
    }
    for (int i = 0; i < kbs1_loc; i++) {
        cout << 4;
    }

    for (int i = kbs1_loc; i > 0; i--) {
        channel[i] = channel[i - 1];
    }
    channel[0] = "KBS1";
    
    for (int i = 0; i < N; i++) {
        if (channel[i] == "KBS2") {
            kbs2_loc = i;
        }
    }

    for (int i = 0; i < kbs2_loc; i++) {
        cout << 1;
    }
    for (int i = 1; i < kbs2_loc; i++) {
        cout << 4;
    }

    return 0;
}