#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, start_time, end_time, next_available_time = 0, result = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> start_time >> end_time;
		pq.push({start_time, end_time});
	}
	while (!pq.empty()){
		if (next_available_time <= pq.top().first){
			next_available_time = pq.top().second;
			result++;
		}
		else if (next_available_time > pq.top().second){
			next_available_time = pq.top().second;
		}
		pq.pop();
	}
	cout << result << "\n";
	return 0;
}