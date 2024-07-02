#include <iostream>
#include <algorithm>
using namespace std;
int n, r, c, result = 0;

void z(int d, int start_r, int start_c){
    if (start_r == r && start_c == c){
        cout << result << "\n";
        return;
    }
    if (r >= start_r && r < start_r + d && c >= start_c && c < start_c + d){
        z(d/2, start_r, start_c);
        z(d/2, start_r, start_c + d/2);
        z(d/2, start_r + d/2, start_c);
        z(d/2, start_r + d/2, start_c + d/2);
    }
    else{
        result += d*d;
        return;
    }
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> r >> c;
    z((1<<n), 0, 0);
    return 0;
}