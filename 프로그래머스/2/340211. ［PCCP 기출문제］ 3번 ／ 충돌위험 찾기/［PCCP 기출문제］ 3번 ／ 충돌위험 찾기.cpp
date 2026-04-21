#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
    현재 지점
    목표 지점
    이동 과정에서의 좌표
    r -> c
*/

struct Robot {
    int goal_idx;
    int r;
    int c;
    bool done;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int N = points.size();
    int X = routes.size();
    int R = routes[0].size();
    
    int answer = 0;
    
    vector<vector<int>> visited(101, vector<int>(101));
    vector<Robot> robots(X);
    for (int i=0; i<X; i++) {
        int start_point_number = routes[i][0];
        robots[i].goal_idx = 1;
        robots[i].r = points[start_point_number - 1][0];
        robots[i].c = points[start_point_number - 1][1];
        robots[i].done = false;
        visited[robots[i].r][robots[i].c] += 1;
    }
    
    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            if (visited[i][j] > 1) answer++;
        }
    }
    
    int done_count = 0;
    
    while (done_count < X) {
        vector<vector<int>> visited(101, vector<int>(101));
        
        for (int i=0; i<X; i++) {
            if (robots[i].done) continue;
            int goal_point = routes[i][robots[i].goal_idx];
            int goal_r = points[goal_point - 1][0];
            int goal_c = points[goal_point - 1][1];
            
            // 이동
            if (robots[i].r != goal_r) {
                if (robots[i].r < goal_r) {
                    robots[i].r += 1;
                }
                else {
                    robots[i].r -= 1;
                }
            }
            else if (robots[i].c != goal_c) {
                if (robots[i].c < goal_c) {
                    robots[i].c += 1;
                }
                else {
                    robots[i].c -= 1;
                }
            }
            visited[robots[i].r][robots[i].c] += 1;
            
            // 도착 확인
            if (robots[i].r == goal_r && robots[i].c == goal_c) {
                robots[i].goal_idx++;
                if (robots[i].goal_idx >= R) {
                    robots[i].done = true;
                    done_count++;
                }
            }
        }
        
        for (int i=1; i<=100; i++) {
            for (int j=1; j<=100; j++) {
                if (visited[i][j] > 1) answer++;
            }
        }
    }
    
    return answer;
}