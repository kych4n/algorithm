#include <iostream>
#include <string>

using namespace std;

/*
    '(' >= ')'
    마지막까지 확인했을 때 '(' == ')'

    *홀수면 안됨
    ** ? 위치부터 무엇인가를 하려고 하면 뒤에 무엇인지 모르기 때문에 애매해짐
        -> 되냐 안되냐만 판단하면 되므로 나중에 끼워넣는다고 생각하면 됨

    
*/

int N;
string records;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> records;

    // Please write your code here.
    if (N % 2 != 0 || records.back() == '(') {
        cout << "No\n";
        return 0;
    }

    int open_count = 0, close_count = 0;
    for (const char& c : records) {
        if (c == '(') open_count++;
        else if (c == ')') close_count++;
    }

    if (open_count > N/2 || close_count > N/2) {
        cout << "No\n";
        return 0;
    }

    string made = "";
    int needed_open_count = N/2 - open_count;
    for (int i=0; i<N; i++) {
        if (records[i] == '?') {
            if (needed_open_count > 0) {
                made += '(';
                needed_open_count--;
            }
            else {
                made += ')';
            }
        }
        else {
            made += records[i];
        }
    }

    int balance = 0;
    for (const char& c : made) {
        if (c == '(') balance++;
        else balance--;

        if (balance < 0) {
            cout << "No\n";
            return 0;
        }
    }

    if (balance == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
