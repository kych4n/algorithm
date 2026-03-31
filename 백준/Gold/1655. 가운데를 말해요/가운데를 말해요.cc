#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    정수를 하나씩 외칠 때마다 중간값을 말해야 한다. 
    개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

    N=10^5
    - 수를 저장은 해야함 -> 어디에?
    - 정렬을 해야 함
    - 우션순위 큐?
    - 가운데를 어떻게 찾을까?
    - 커서 문제처럼 두 개
    - 오름차순 큐(커서 오른쪽), 내림차순 큐(커서 왼쪽)
    - 내림차순 큐의 크기는 오름차순 큐의 크기+1 또는 오름차순 큐의 크기와 같다
    - 내 == 오 -> 내림차순 큐에 추가를 해야 하는데, 
            오top보다 크다면 오top을 내에 넣고 오에 추가
            오top보다 작다면 내에 추가
    - 내 > 오 -> 오름차순 큐에 추가를 해야 하는데,
            내top보다 작다면 내top을 오에 넣고 내에 추가
            내top보다 크다면 오에 추가
      
*/

int N, number;
priority_queue<int> leftq;  // 내림차순
priority_queue<int, vector<int>, greater<int>> rightq;    // 오름차순

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> number;
        if (leftq.empty()) {
            leftq.push(number);
            cout << leftq.top() << "\n";
            continue;
        }
        if (leftq.size() == rightq.size()) {
            if (rightq.top() < number) {
                leftq.push(rightq.top());
                rightq.pop();
                rightq.push(number);
            }
            else {
                leftq.push(number);
            }
        }
        else if (leftq.size() > rightq.size()) {
            if (leftq.top() > number) {
                rightq.push(leftq.top());
                leftq.pop();
                leftq.push(number);
            }
            else {
                rightq.push(number);
            }
        }
        cout << leftq.top() << "\n";
    }

    return 0;
}