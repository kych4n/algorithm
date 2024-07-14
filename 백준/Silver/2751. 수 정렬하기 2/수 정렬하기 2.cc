#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, m;

int main(void){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> m;
		pq.push(m);
	}

	while (!pq.empty()){
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}