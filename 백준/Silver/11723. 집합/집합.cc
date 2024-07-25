#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, x;
string oper;
vector<int> set(21);

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> oper;
        if (oper == "add") {
            cin >> x;
            set[x] = 1;
        }
        else if (oper == "remove") {
            cin >> x;
            set[x] = 0;
        }
        else if (oper == "check") {
            cin >> x;
            cout << set[x] << "\n";
        }
        else if (oper == "toggle") {
            cin >> x;
            set[x] = (set[x] == 1 ? 0 : 1);
        }
        else if (oper == "all") {
            for (int j = 1; j <= 20; j++) {
                set[j] = 1;
            }
        }
        else if (oper == "empty") {
            for (int j = 1; j <= 20; j++) {
                set[j] = 0;
            }
        }
    }
	
	return 0;
}