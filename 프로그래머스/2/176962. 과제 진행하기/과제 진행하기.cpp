#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
    1. 시작 시각이 빠른 것부터 시작
    2. 다른 과제의 시작 시각이 되면 멈추고 그 과제를 시작
    3. 다른 과제의 시작 시각이 아직 되지 않았으면, 멈춘 과제를 시작 -> 마지막 과제가 끝난 시각
*/

struct Assignment {
    string subject;
    int start;
    int need;
};

int toMinutes(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
    int N = plans.size();
    
    vector<Assignment> A(N);
    
    for (int i=0; i<N; i++) {
        A[i].subject = plans[i][0];
        A[i].start = toMinutes(plans[i][1]);
        A[i].need = stoi(plans[i][2]);
    }
    
    sort(A.begin(), A.end(), [&](const Assignment& a, const Assignment& b) {
       return a.start < b.start; 
    });
    
    vector<string> answer;
    stack<Assignment> s;
    
    for (int i=0; i<N; i++) {
        if (i==N-1) {
            answer.push_back(A[i].subject);
            break;
        }
        
        int curStart = A[i].start;
        int curNeed = A[i].need;
        int nextStart = A[i+1].start;
        int available = nextStart-curStart;
        
        if (curNeed <= available) {
            available -= curNeed;
            answer.push_back(A[i].subject);
            
            while (available > 0 && !s.empty()) {
                if (s.top().need <= available) {
                    available -= s.top().need;
                    answer.push_back(s.top().subject);
                    s.pop();
                }
                else {
                    s.top().need -= available;
                    available = 0;
                }
            }
        }
        else {
            A[i].need -= available;
            s.push(A[i]);
        }
    }
    
    while (!s.empty()) {
        answer.push_back(s.top().subject);
        s.pop();
    }
    
    return answer;
}