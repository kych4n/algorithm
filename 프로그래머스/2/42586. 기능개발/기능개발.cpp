#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    queue<int> q;
    for (int i=0; i<size; i++) {
        int day = (100-progresses[i])/speeds[i];
        if ((100-progresses[i])%speeds[i] > 0) {
            day += 1;
        }
        q.push(day);
    }
    while (!q.empty()) {
        int deploy_amount = 0;
        int target = q.front();
        q.pop();
        deploy_amount += 1;
        int cur_size = q.size();
        for (int i=0; i<cur_size; i++) {
            if (target >= q.front()) {
                deploy_amount += 1;
                q.pop();
            }
            else {
                break;
            }
        }
        answer.push_back(deploy_amount);
    }
    
    
    return answer;
}