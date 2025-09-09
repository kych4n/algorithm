#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;	
int n, k, sec=0;
vector<int> visited(100001, 1e9+7);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	if (n==k){
		cout << 0 << "\n";
		return 0;
	}		
	queue<int> q;
	q.push(n);
	while (!q.empty()){
		sec+=1;
		int size = q.size();
		for (int i=0; i<size; i++){
			int x = q.front();
			q.pop();
			if (x+1 <= 100000){
				if (visited[x+1] > sec){
					visited[x+1] = sec;
					q.push(x+1);
				}
			} 
			if (x-1 >= 0){
				if (visited[x-1] > sec){
					visited[x-1] = sec;
					q.push(x-1);
				}
			} 
			if (x*2 <= 100000){
				if (visited[x*2] > sec){
					visited[x*2] = sec;
					q.push(x*2);
				}
			} 
		}
	}
	cout << visited[k] << "\n";
	return 0;
}